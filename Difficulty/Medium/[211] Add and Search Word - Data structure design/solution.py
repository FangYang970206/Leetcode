class TrieNode:
    def __init__(self):
        self.links = [None] * 26
        self.is_end = False

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        cur = self.root
        for i in range(len(word)):
            index = ord(word[i]) - ord('a')
            if cur.links[index] == None:
                cur.links[index] = TrieNode()
            cur = cur.links[index]
        cur.is_end = True
    
    def _isMatch(self, node, word, start):
        if start == len(word): return node.is_end
        alpha = word[start]
        if alpha == '.':
            for i in range(26):
                if node.links[i] and self._isMatch(node.links[i], word, start + 1):
                    return True
            return False
        else:
            index = ord(alpha) - ord('a')
            if node.links[index]:
                return self._isMatch(node.links[index], word, start + 1)
            else:
                return False

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self._isMatch(self.root, word, 0)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)