#
# @lc app=leetcode id=113 lang=python3
#
# [113] Path Sum II
#
# https://leetcode.com/problems/path-sum-ii/description/
#
# algorithms
# Medium (58.56%)
# Likes:    7939
# Dislikes: 154
# Total Accepted:    875.4K
# Total Submissions: 1.5M
# Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
#
# Given the root of a binary tree and an integer targetSum, return all
# root-to-leaf paths where the sum of the node values in the path equals
# targetSum. Each path should be returned as a list of the node values, not
# node references.
# 
# A root-to-leaf path is a path starting from the root and ending at any leaf
# node. A leaf is a node with no children.
# 
# 
# Example 1:
# 
# 
# Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
# Output: [[5,4,11,2],[5,8,4,5]]
# Explanation: There are two paths whose sum equals targetSum:
# 5 + 4 + 11 + 2 = 22
# 5 + 8 + 4 + 5 = 22
# 
# 
# Example 2:
# 
# 
# Input: root = [1,2,3], targetSum = 5
# Output: []
# 
# 
# Example 3:
# 
# 
# Input: root = [1,2], targetSum = 0
# Output: []
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [0, 5000].
# -1000 <= Node.val <= 1000
# -1000 <= targetSum <= 1000
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        path = []
        self.dfs(root, targetSum, path, ans)
        return ans
    
    def dfs(self, root, targetSum, path, ans):
        if not root:
            return
        if not root.left and not root.right:
            if root.val == targetSum:
                ans.append(path[:] + [root.val])
        
        targetSum -= root.val
        path.append(root.val)
        self.dfs(root.left, targetSum, path, ans)
        self.dfs(root.right, targetSum, path, ans)
        path.pop()

# @lc code=end

