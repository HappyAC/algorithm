package kmp

import (
	"reflect"
	"testing"
)

func TestGetNextTable(t *testing.T) {
	pattern := "ababaaababaa"
	nexts := getNextTable(pattern)
	if !reflect.DeepEqual(nexts, []int{-1, 0, 0, 1, 2, 3, 1, 1, 2, 3, 4, 5}) {
		t.Error(nexts, "not equal with", []int{-1, 0, 0, 1, 2, 3, 1, 1, 2, 3, 4, 5})
	}
}

func TestIndexOf(t *testing.T) {
	pattern := "ababaaababaa"
	str := "ababaaababaa"
	if IndexOf(str, pattern) != 0 {
		t.Error(pattern, "not match", str)
	}
	pattern = "ababaaababaa"
	str = "ababaaababa"
	if IndexOf(str, pattern) != -1 {
		t.Error(pattern, "match error", str)
	}

	pattern = "baaa"
	str = "ababaaababaa"
	if IndexOf(str, pattern) != 3 {
		t.Error(pattern, "match error", str, "index:", IndexOf(str, pattern))
	}
}
