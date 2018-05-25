package skiplist

import (
	"fmt"
	"testing"
)

func TestSkipList(t *testing.T) {
	skipList := NewSkipList(3)
	fmt.Println("test insert 1 3 5 7 9")
	for i := 1; i < 10; i += 2 {
		ok := skipList.Insert(i, i)
		if ok != true {
			t.Error("insert", i, "failed")
		}
	}
	skipList.Print()

	fmt.Println("test insert 2 4 6 8 10")
	for i := 2; i < 10; i += 2 {
		ok := skipList.Insert(i, i)
		if ok != true {
			t.Error("insert", i, "failed")
		}
	}
	skipList.Print()
	fmt.Println("test find 1...9")
	for i := 1; i < 10; i++ {
		value, exist := skipList.Find(i)
		if value != i || !exist {
			t.Error(i, "not found")
		}
	}
	fmt.Println("test delete 1 4 5 6 9")
	needDeletes := []int{1, 4, 5, 6, 9}
	// delete
	for _, i := range needDeletes {
		ok := skipList.Delete(i)
		if !ok {
			t.Error("delete", i, "failed")
		}
	}
	// check
	for _, i := range needDeletes {
		_, exist := skipList.Find(i)
		if exist {
			t.Error("delete", i, "failed")
		}
	}
	if skipList.Size != 4 {
		t.Error("update size failed")
	}
}
