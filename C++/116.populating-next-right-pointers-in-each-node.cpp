/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (40.58%)
 * Likes:    1370
 * Dislikes: 130
 * Total Accepted:    293.4K
 * Total Submissions: 719.5K
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition:
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
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node, just like
 * in Figure B. The serialized output is in level order as connected by the
 * next pointers, with '#' signifying the end of each level.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is less than 4096.
 * -1000 <= node.val <= 1000
 * 
 * 
 */

/*
// Definition for a Node.
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
        // if (root==nullptr) return root;
        
        // Node* cur = root;
        // while (cur->left) {
        //     Node* tmp = cur->left;
        //     while (cur) {
        //         cur->left->next = cur->right;
        //         if (cur->next) {
        //             cur->right->next = cur->next->left;
        //         }
        //         cur = cur->next;
        //     }
        //     cur = tmp;
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

