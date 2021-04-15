package main

import (
	"fmt"
)

type trie struct {
	children []*trie
	parent   *trie
	freq     int
	data     rune
	id       int
	isEnd    bool
}

func NewTrie() *trie {
	return &trie{}
}

func (t *trie) add(data rune) *trie {
	trie := NewTrie()
	trie.data = data
	trie.parent = t
	t.children = append(t.children, trie)

	return trie
}

func (t *trie) Insert(data string) {
out:
	for _, s := range data {
		for _, child := range t.children {
			if child.data == s {
				t = child
				continue out
			}
		}
		t = t.add(s)
	}
	t.isEnd = true
}

func (t trie) Search(data string) *trie {
	if len(data) == 0 {
		return &t
	}

	b := data[0]
	data = data[1:]

	for _, child := range t.children {
		if child.data == rune(b) {
			return child.Search(data)
		}
	}

	return nil
}

func (t trie) Print() {
	fmt.Printf("%c", t.data)
	for _, child := range t.children {
		child.Print()
	}
}

func (t trie) PrintR() {
	if t.isEnd {
		t.PrintPath()
	}

	for _, child := range t.children {
		child.PrintR()
	}
}

func (t trie) PrintPath() {
	var r []rune

	for t.parent != nil {
		r = append(r, t.data)
		t = *t.parent
	}

	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}

	for _, v := range r {
		fmt.Printf("%c", v)
	}
	fmt.Println()
}

func main() {
	t := NewTrie()
	t.Insert("hello")
	t.Insert("hi")
	t.Insert("cat")
	t.Insert("category")
	r := t.Search("h")
	if r != nil {
		r.PrintR()
	}
}
