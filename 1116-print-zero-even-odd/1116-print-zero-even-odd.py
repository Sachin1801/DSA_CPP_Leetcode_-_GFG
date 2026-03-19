from threading import Lock

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.odd_even = 1
        self.l0 = Lock()
        self.l1 = Lock()
        self.l2 = Lock()
        self.l1.acquire()
        self.l2.acquire()
        self.curr_size = 0
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        
        for i in range(1, self.n + 1):
            self.l0.acquire()
            printNumber(0)
            # self.curr_size += 1

            #if even number next then release l2        
            if i % 2 == 0:
                self.l2.release()
            else:
                self.l1.release()
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n+1, 2):
            self.l2.acquire()
            printNumber(i)
                # self.curr_size += 1
                # self.odd_even += 1
                # if(self.curr_size == 2*self.n):
                #     return
            self.l0.release()
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n+1, 2):
            self.l1.acquire()
            printNumber(i)
                # self.curr_size += 1 
                # self.odd_even += 1
                # if(self.curr_size == 2*self.n):
                #     return
            self.l0.release()

            