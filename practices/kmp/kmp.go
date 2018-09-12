package kmp

// next table saved the index to jump
// when match failed at pattern[i]
func getNextTable(pattern string) []int {
	next := make([]int, len(pattern))
	next[0] = -1
	i, j := 1, 0
	for i < len(pattern) {
		if j == -1 || pattern[i] == pattern[j] {
			next[i] = j
			i++
			j++
		} else {
			if j == 0 {
				next[i] = -1
				i++
			} else {
				j = next[j-1] + 1
			}
		}
	}
	// shift right
	for k := len(pattern) - 1; k >= 1; k-- {
		next[k] = next[k-1] + 1

	}

	return next
}

// IndexOf return the index of pattern in str
// if pattern not match return -1
func IndexOf(str, pattern string) int {
	nexts := getNextTable(pattern)
	i, j := 0, 0
	for i < len(str) && j != len(pattern) {
		if str[i] == pattern[j] {
			i++
			j++
		} else {
			if nexts[j] == -1 {
				i++
				continue
			}
			j = nexts[j]
		}
	}
	if j == len(pattern) {
		return i - j
	}
	return -1
}
