/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tmp = head;
        int length = 0;
        while (tmp) {
            length++;
            tmp = tmp->next;
        }
        vector<int> nums(length, 0);
        length = 0;
        while (head) {
            nums[length] = head->val;
            length++;
            head = head->next;
        }
        return sortedListToBSTHelper(nums, 0, nums.size());
    }

    TreeNode* sortedListToBSTHelper(vector<int>& nums, int begin, int end) {
        if (end - begin < 1)
            return nullptr;
        TreeNode* root = new TreeNode(nums[(begin + end)/2]);
        root->left = sortedListToBSTHelper(nums, begin, (begin + end) / 2);
        root->right = sortedListToBSTHelper(nums, (begin + end) / 2 + 1, end);
        return root;
    }
};
// @lc code=end

