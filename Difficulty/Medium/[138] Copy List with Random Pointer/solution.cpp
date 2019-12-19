/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> m;
        vector<Node*> record;
        int i = 0;
        Node *new_head = new Node(0);
        Node *tmp = head, *new_tmp = new_head;
        while (tmp) {
            new_tmp->next = new Node(tmp->val);
            m[tmp] = i;
            new_tmp = new_tmp->next;
            tmp = tmp->next;
            record.push_back(new_tmp);
            i++;
        }
        tmp = head;
        new_tmp = new_head;
        while (tmp) {
            if (tmp->random)
                new_tmp->next->random = record[m[tmp->random]];
            else
                new_tmp->next->random = nullptr;
            tmp = tmp->next;
            new_tmp = new_tmp->next;
        }
        return new_head->next;
    }
};
// @lc code=end

