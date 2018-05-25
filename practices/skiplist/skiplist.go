package skiplist

import (
	"fmt"
	"math/rand"
	"time"
)

// SkipList skiplist
type SkipList struct {
	head     *Node
	maxLevel int
	Size     uint
}

// KeyType
type KeyType = int

// ValueType
type ValueType = int

// NewSkipList return a new skiplist
func NewSkipList(maxLevel int) *SkipList {
	return &SkipList{
		maxLevel: maxLevel,
		head:     newNode(0, 0, maxLevel),
		Size:     0,
	}
}

// Find find node's value by key
func (list *SkipList) Find(key KeyType) (result ValueType, exist bool) {
	node := list.FindNode(key)
	if node == nil {
		exist = false
		return
	}
	return node.Data, true
}

// FindNode find node by key
func (list *SkipList) FindNode(key KeyType) (result *Node) {
	p := list.head

	for {
		// node.key equal key and not the list head
		if p.Key == key && p != list.head {
			return p
		}

		gotoNext := false
		for i := p.Level - 1; i >= 0; i-- {
			nextNode := p.nextNodes[i]
			// ignore nil pointer
			if nextNode == nil {
				continue
			}
			// skip to next node
			if nextNode.Key <= key {
				p = nextNode
				gotoNext = true
				break
			}
		}
		if gotoNext {
			continue
		}
		// not found
		return nil
	}
}

var srand = rand.NewSource(time.Now().UnixNano())

func randomLevel(maxLevel int) int {
	return (rand.New(srand).Intn(int(maxLevel)) + 1)
}

func (list *SkipList) insertNewNode(updates []*Node, nodeNew *Node) {
	for k := nodeNew.Level - 1; k >= 0; k-- {
		// update the next nodes of new node with the previous node
		nodeNew.nextNodes[k] = updates[k].nextNodes[k]
		// update the next nodes of previous node to new node
		updates[k].nextNodes[k] = nodeNew
	}
	list.Size++
}

// Insert insert a node to skiplist
func (list *SkipList) Insert(key KeyType, value ValueType) (ok bool) {
	p := list.head
	updates := make([]*Node, list.maxLevel)
	currentLevel := list.maxLevel
	// find the first node that gather than inster key
	for {
		gotoNext := false
		for i := p.Level - 1; i >= 0; i-- {
			nextNode := p.nextNodes[i]
			if nextNode == nil {
				updates[currentLevel-1] = p
				currentLevel--
				continue
			}
			if nextNode.Key == key {
				return false
			} else if nextNode.Key < key {
				p = nextNode
				gotoNext = true
				updates[currentLevel-1] = p
				break
			} else if nextNode.Key > key && currentLevel == 1 {
				updates[currentLevel-1] = p
				nodeNew := newNode(key, value, randomLevel(list.maxLevel))
				list.insertNewNode(updates, nodeNew)
				return true
			}
			updates[currentLevel-1] = p
			currentLevel--
		}
		// not find insert to tail
		if !gotoNext {
			nodeNew := newNode(key, value, randomLevel(list.maxLevel))
			list.insertNewNode(updates, nodeNew)
			return true
		}
	}
}

// Delete delete a node from skiplist
func (list *SkipList) Delete(key KeyType) (ok bool) {
	p := list.head
	updates := make([]*Node, list.maxLevel)
	currentLevel := list.maxLevel
	// find the first node that equal inster key
	for {
		gotoNext := false
		for i := p.Level - 1; i >= 0; i-- {
			nextNode := p.nextNodes[i]
			if nextNode == nil {
				currentLevel--
				continue
			}
			if nextNode.Key < key {
				p = nextNode
				gotoNext = true
				break
			} else if nextNode.Key == key {
				updates[currentLevel-1] = p
				if currentLevel == 1 {
					for k := nextNode.Level - 1; k >= 0; k-- {
						updates[k].nextNodes[k] = nextNode.nextNodes[k]
					}
					list.Size--
					return true
				}

			}
			currentLevel--
		}
		// not found
		if !gotoNext {
			return false
		}
	}
}

// Print skiplist
func (list *SkipList) Print() {
	for level := list.maxLevel - 1; level >= 0; level-- {
		p := list.head
		for {
			if p == list.head {
				fmt.Printf("(head)")
				p = p.nextNodes[0]
				continue
			}
			if p == nil {
				fmt.Printf("===>(nil)")
				break
			}

			if p.Level-1 >= level {
				fmt.Printf("===>(%d)", p.Key)
			} else {
				fmt.Printf("=======")
			}
			p = p.nextNodes[0]

		}
		fmt.Printf("\n")
	}
	fmt.Printf("Size: %d\n\n", list.Size)
}

// Node skip list node
type Node struct {
	Level     int
	Key       KeyType
	Data      ValueType
	nextNodes []*Node
}

func newNode(key KeyType, data ValueType, level int) *Node {
	return &Node{
		Key:       key,
		Data:      data,
		Level:     level,
		nextNodes: make([]*Node, level),
	}
}
