class TrieNode:
    def __init__(self, is_end = False):
        self.is_end = is_end
        self.links = [None] * 26;

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode();
    
    def searchUtil(self, word):
        cur = self.root
        for c in word:
            index = ord(c) - ord('a')
            if cur.links[index] != None:
                cur = cur.links[index]
            else:
                return None
        return cur
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        cur = self.root
        for c in word:
            index = ord(c) - ord('a')
            if cur.links[index] == None:
                cur.links[index] = TrieNode()
            cur = cur.links[index]
        cur.is_end = True


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        cur = self.searchUtil(word)
        return cur != None and cur.is_end


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        return self.searchUtil(prefix) != None


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)