/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
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
        Node *pre = root, *cur = nullptr;
        while (pre) {
            cur = pre;
            while(cur) {
                Node *n = nullptr;
                if (cur->left) {
                    if (cur->right)
                        cur->left->next = cur->right;
                    else{
                        n = cur->next;
                        while(n){
                            if (n->left){
                                cur->left->next = n->left;
                                break;
                            }
                            if (n->right){
                                cur->left->next = n->right;
                                break;
                            }
                            n = n->next;  
                        }
                    }
                }
                if (cur->right){
                    n = cur->next;
                    while(n){
                        if (n->left){
                            cur->right->next = n->left;
                            break;
                        }
                        if (n->right){
                            cur->right->next = n->right;
                            break;
                        }
                        n = n->next; 
                    }
                }
                cur = n;
            }
            while(pre){
                if (pre->left) {
                    if (pre->left->left || pre->left->right) {
                        pre = pre->left;
                        break;
                    }
                }
                if (pre->right){
                    if (pre->right->left || pre->right->right){
                        pre = pre->right;
                        break;
                    }
                }
                pre = pre->next;
            }
        }
        return root;
    }
};
// @lc code=end

