namespace LeetCodeProblems.Problems;
using System.Threading;
public class LeetCode1115PrintFooBarAlternately
{
    public class FooBar {
        private int n;
        SemaphoreSlim fooSemaphore = new SemaphoreSlim(1, 1);
        SemaphoreSlim barSemaphore = new SemaphoreSlim(0, 1);

        public FooBar(int n) {
            this.n = n;
        }

        public void Foo(Action printFoo) {
        
            for (int i = 0; i < n; i++) {
            
                // printFoo() outputs "foo". Do not change or remove this line.
                fooSemaphore.Wait();
                printFoo();
                barSemaphore.Release();
       
            }
        }

        public void Bar(Action printBar) {
        
            for (int i = 0; i < n; i++) {
            
                // printBar() outputs "bar". Do not change or remove this line.
                barSemaphore.Wait();
                printBar();
                fooSemaphore.Release();
            }
        }
    }
}