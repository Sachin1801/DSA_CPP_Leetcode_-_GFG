class Fancy:

    def __init__(self):
        self.store = []
        self.add = 0
        self.mul = 1
        self.MOD = 10**9 + 7        

    def append(self, val: int) -> None:
        to_store = (val - self.add) % self.MOD
        to_store = (to_store * pow(self.mul,-1,self.MOD)) % self.MOD
        self.store.append(to_store) 

    def addAll(self, inc: int) -> None:
        self.add = (self.add + inc ) % self.MOD

    def multAll(self, m: int) -> None:
        self.mul = self.mul * m % self.MOD
        self.add = self.add * m % self.MOD

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.store):
            return -1
        
        val = (((self.store[idx] * self.mul % self.MOD )% self.MOD) + self.add)% self.MOD
        return val
        


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)