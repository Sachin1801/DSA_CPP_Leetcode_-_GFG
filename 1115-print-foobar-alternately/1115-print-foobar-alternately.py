from threading import Lock

class FooBar:
    def __init__(self, n):
        self.n = n
        self.l1 = Lock()
        self.l2 = Lock()
        self.l2.acquire()


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            # printFoo() outputs "foo". Do not change or remove this line.
            self.l1.acquire()
            printFoo()
            self.l2.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            # printBar() outputs "bar". Do not change or remove this line.
            self.l2.acquire()
            printBar()
            self.l1.release()