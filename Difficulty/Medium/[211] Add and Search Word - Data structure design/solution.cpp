/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */

// @lc code=start
class WordDictionary {
private:
    struct TrieNode{
        TrieNode *links[26];
        bool is_end;
        TrieNode(bool is_end = false) {
            this->is_end = is_end;
            memset(links, 0, sizeof(links));
        }
    };
    bool is_match(TrieNode* root, const string& word, int start) {
        if (start == word.size()) return root->is_end;
        char alpha = word[start];
        if (alpha == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->links[i] && is_match(root->links[i], word, start + 1))
                    return true;
            }
            return false;
        } else {
            if (root->links[alpha - 'a'] == 0)
                return false;
            return is_match(root->links[alpha - 'a'], word, start + 1);
        }
    }
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (cur->links[index] == 0) {
                cur->links[index] = new TrieNode();
            }
            cur = cur->links[index];
        }
        cur->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return is_match(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

