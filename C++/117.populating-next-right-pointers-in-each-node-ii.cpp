/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (36.36%)
 * Likes:    1174
 * Dislikes: 165
 * Total Accepted:    215.2K
 * Total Submissions: 590.1K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * Given a binary tree
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not
 * count as extra space for this problem.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B. The serialized output is in level order as connected by the next
 * pointers, with '#' signifying the end of each level.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
 * 
 * 
 */

#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start

class Solution {
public:
    Node* connect(Node* root) {
        // if (root==NULL) return root;

        // Node *cur = root;
        // while (cur) {
        //     Node dummy(0);
        //     Node *tail = &dummy;

        //     // cur level
        //     while (cur) {
        //         if (cur->left != NULL) {
        //             tail->next = cur->left;
        //             tail = tail->next;
        //         }
        //         if (cur->right != NULL) {
        //             tail->next = cur->right;
        //             tail = tail->next;
        //         }
        //         cur = cur->next;
        //     }
        //     // next level
        //     cur = dummy.next;
        // }
        // return root;

        if (!root) return NULL;
        
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            for (int i=0; i<q_size; ++i) {
                Node *node = q.front(); q.pop();
                if (i < q_size-1) {
                    node->next = q.front();
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

