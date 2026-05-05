import random

class RandomizedSet:

    def __init__(self):
        self.hashmap = {}
        self.list = []

    def insert(self, val: int) -> bool:
        if val in self.hashmap: return True 
        
        self.list.append(val)
        self.hashmap[val] = len(self.list) - 1
        return False

    def remove(self, val: int) -> bool:
        if val not in self.hashmap: return False 
        index = self.hashmap.pop(val)
        return True 

    def getRandom(self) -> int:
        index = random.randint(0, len(self.list) - 1)
        while self.list[index] not in self.hashmap:
            index = random.randint(0, len(self.list) - 1)
        return self.list[index]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()