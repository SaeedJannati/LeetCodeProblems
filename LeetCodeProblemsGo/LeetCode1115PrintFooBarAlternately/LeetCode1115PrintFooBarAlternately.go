package LeetCode1115PrintFooBarAlternately

import "sync"

type FooBar struct {
	n        int
	fooMutex sync.Mutex
	barMutex sync.Mutex
}

func NewFooBar(n int) *FooBar {
	result := &FooBar{n: n}
	result.barMutex.Lock()
	return result
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {
		fb.fooMutex.Lock()
		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo()
		fb.barMutex.Unlock()
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		fb.barMutex.Lock()
		// printBar() outputs "bar". Do not change or remove this line.
		printBar()
		fb.fooMutex.Unlock()
	}
}
