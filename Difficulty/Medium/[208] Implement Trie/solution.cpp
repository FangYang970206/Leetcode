/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
struct TrieNode{
    TrieNode* links[26];
    bool is_end;
    TrieNode(bool is_end = false) {
        memset(links, 0, sizeof(links));
        this->is_end = is_end;
    }
};

class Trie {
private:
    TrieNode* root;
    void clear(TrieNode *root){
        for(int i = 0; i < 26; i++){
            if(root->links[i] != nullptr){
                clear(root->links[i]);
            }
        }
        delete root;
    }
    TrieNode* searchUtil(const string& s) {
        TrieNode* cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->links[s[i] - 'a'] != nullptr)
                cur = cur->links[s[i] - 'a'];
            else
                return nullptr;
        }
        return cur;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->links[index] == nullptr) {
                cur->links[index] = new TrieNode();
            }
            cur = cur->links[index];
        }
        cur->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* res = searchUtil(word);
        return  res != nullptr && res->is_end == true; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchUtil(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

