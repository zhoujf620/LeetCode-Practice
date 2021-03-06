#
# @lc app=leetcode id=144 lang=python
#
# [144] Binary Tree Preorder Traversal
#
# https://leetcode.com/problems/binary-tree-preorder-traversal/description/
#
# algorithms
# Medium (53.01%)
# Likes:    1032
# Dislikes: 46
# Total Accepted:    399.4K
# Total Submissions: 751K
# Testcase Example:  '[1,null,2,3]'
#
# Given a binary tree, return the preorder traversal of its nodes' values.
# 
# Example:
# 
# 
# Input: [1,null,2,3]
# ⁠  1
# ⁠   \
# ⁠    2
# ⁠   /
# ⁠  3
# 
# Output: [1,2,3]
# 
# 
# Follow up: Recursive solution is trivial, could you do it iteratively?
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
    #     res = []
    #     self.dfs(root, res)
    #     return res  
    
    # def dfs(self, root, res):
    #     if not root:
    #         return 
    #     res.append(root.val)
    #     self.dfs(root.left, res)
    #     self.dfs(root.right, res)

        if not root:
            return []
            
        res = []
        stack = [root]
        while stack:

            cur = stack.pop()    
            if cur:
                res.append(cur.val)
                stack.append(cur.right)
                stack.append(cur.left)        

        return res
        
# @lc code=end

