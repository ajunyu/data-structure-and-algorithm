package main

import (
	"fmt"
)

type node struct {
	children []*node
	parent   *node
	freq     int
	data     rune
	id       int
	isEnd    bool
}

func NewNode() *node {
	return &node{}
}

func (n *node) add(data rune) *node {
	node := NewNode()
	node.data = data
	node.parent = n
	n.children = append(n.children, node)

	return node
}

func (n *node) Insert(data string) {
out:
	for _, s := range data {
		for _, child := range n.children {
			if child.data == s {
				n = child
				continue out
			}
		}
		n = n.add(s)
	}
	n.isEnd = true
}

func (n node) Search(data string) *node {
	if len(data) == 0 {
		return &n
	}

	b := data[0]
	data = data[1:]

	for _, child := range n.children {
		if child.data == rune(b) {
			return child.Search(data)
		}
	}

	return nil
}

func (n node) Print() {
	fmt.Printf("%c", n.data)
	for _, child := range n.children {
		child.Print()
	}
}

func (n node) PrintR() {
	if n.isEnd {
		n.PrintPath()
	}

	for _, child := range n.children {
		child.PrintR()
	}
}

func (n node) PrintPath() {
	var r []rune

	for n.parent != nil {
		r = append(r, n.data)
		n = *n.parent
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
	r := NewNode()
	r.Insert("hello")
	r.Insert("hi")
	r.Insert("cat")
	r.Insert("category")
	n := r.Search("h")
	if n != nil {
		n.PrintR()
	}
}
