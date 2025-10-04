//
// Created by saeed on 10/4/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1115PRINTFOOBARALTERNATELY_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1115PRINTFOOBARALTERNATELY_H
#include <functional>
#include <mutex>

using namespace std;

class LeetCode1115PrintFooBarAlternately {
    class FooBar {
    private:
        int n;
        mutex fooMutex{};
        mutex barMutex{};

    public:
        FooBar(int n) {
            this->n = n;
            barMutex.lock();
        }

        void foo(function<void()> printFoo) {
            for (int i = 0; i < n; i++) {
                // printFoo() outputs "foo". Do not change or remove this line.
                fooMutex.lock();
                printFoo();
                barMutex.unlock();
            }
        }

        void bar(function<void()> printBar) {
            for (int i = 0; i < n; i++) {
                // printBar() outputs "bar". Do not change or remove this line.
                barMutex.lock();
                printBar();
                fooMutex.unlock();
            }
        }
    };
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1115PRINTFOOBARALTERNATELY_H
