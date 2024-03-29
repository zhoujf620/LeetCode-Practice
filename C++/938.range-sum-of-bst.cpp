/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 *
 * https://leetcode.com/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Easy (81.45%)
 * Likes:    1482
 * Dislikes: 245
 * Total Accepted:    252.9K
 * Total Submissions: 309.4K
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * Given the root node of a binary search tree, return the sum of values of all
 * nodes with value between L and R (inclusive).
 * 
 * The binary search tree is guaranteed to have unique values.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
 * Output: 32
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
 * Output: 23
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree is at most 10000.
 * The final answer is guaranteed to be less than 2^31.
 * 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        DFS(root, L, R, ans);;
        return ans;
    }
    void DFS(TreeNode* root, int L, int R, int& ans) {
        if (!root) return;
        int num = root->val;
        if (num < L)
            DFS(root->right, L, R, ans);
        else if (num > R)
            DFS(root->left, L, R, ans);
        else {
            ans += num;
            DFS(root->left, L, R, ans);
            DFS(root->right, L, R, ans);
        }
    }
};
// @lc code=end

