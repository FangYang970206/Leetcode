/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node *pre = nullptr;
            while (size--) {
                Node* n = q.front();
                if (!pre){
                    pre = n;
                }else {
                    pre->next = n;
                    pre = n;
                }
                if (n->left){
                    q.push(n->left);
                    q.push(n->right);
                }
                q.pop();
            }
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;
        connectNode(root->left, root->right);
        return root;
    }

    void connectNode(Node* leftNode, Node* rightNode) {
        leftNode->next = rightNode;
        if (leftNode->left) {
            connectNode(leftNode->left, leftNode->right);
            connectNode(leftNode->right, rightNode->left);
            connectNode(rightNode->left, rightNode->right);
        }
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node *pre = root, *cur = nullptr;
        while(pre->left) {
            cur = pre;
            while(cur){
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }
};


// @lc code=end

