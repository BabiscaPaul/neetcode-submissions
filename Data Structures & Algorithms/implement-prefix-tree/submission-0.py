class Node:
    def __init__(self, is_word=False, children=None):
        self.is_word = is_word
        self.children = children if children is not None else {}

class PrefixTree:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        root = self.root
        
        for char in word:
            if char not in root.children:
                root.children[char] = Node()
            root = root.children[char]
            
        root.is_word = True

    def search(self, word: str) -> bool:
        root = self.root
        
        for char in word:
            if char in root.children: root = root.children[char]
            else: return False 
        
        return root.is_word 

    def startsWith(self, prefix: str) -> bool:
        root = self.root
        
        for char in prefix:
            if char in root.children: root = root.children[char]
            else: return False 
        
        return True