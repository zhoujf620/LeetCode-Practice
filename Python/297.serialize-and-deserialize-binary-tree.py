#
# @lc app=leetcode id=297 lang=python3
#
# [297] Serialize and Deserialize Binary Tree
#
# https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
#
# algorithms
# Hard (56.85%)
# Likes:    10126
# Dislikes: 395
# Total Accepted:    890.3K
# Total Submissions: 1.6M
# Testcase Example:  '[1,2,3,null,null,4,5]'
#
# Serialization is the process of converting a data structure or object into a
# sequence of bits so that it can be stored in a file or memory buffer, or
# transmitted across a network connection link to be reconstructed later in the
# same or another computer environment.
# 
# Design an algorithm to serialize and deserialize a binary tree. There is no
# restriction on how your serialization/deserialization algorithm should work.
# You just need to ensure that a binary tree can be serialized to a string and
# this string can be deserialized to the original tree structure.
# 
# Clarification: The input/output format is the same as how LeetCode serializes
# a binary tree. You do not necessarily need to follow this format, so please
# be creative and come up with different approaches yourself.
# 
# 
# Example 1:
# 
# 
# Input: root = [1,2,3,null,null,4,5]
# Output: [1,2,3,null,null,4,5]
# 
# 
# Example 2:
# 
# 
# Input: root = []
# Output: []
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [0, 10^4].
# -1000 <= Node.val <= 1000
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        ans = ""

        queue = deque()
        queue.append(root)
        while queue:
            node = queue.popleft()
            if not node:
                ans += "# "
            else:
                ans += str(node.val) + " "
                queue.append(node.left)
                queue.append(node.right)

        return ans[:-1]
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        
        nums = data.split(" ")
        idx = 0

        if nums[idx] == "#":
            return None

        root = TreeNode(int(nums[idx]))
        idx += 1

        queue = deque()
        queue.append(root)
        while queue:
            node = queue.popleft()

            if nums[idx] != "#":
                node.left = TreeNode(int(nums[idx]))
                queue.append(node.left)
            idx += 1

            if nums[idx] != "#":
                node.right = TreeNode(int(nums[idx])) 
                queue.append(node.right)
            idx += 1

        return root
    

        nums = data.split(" ")
        nodes = []
        for i in range(len(nums)):
            if nums[i] == "#":
                nodes.append(None)
            else:
                nodes.append(TreeNode(int(nums[i])))
        
        idx = 1
        for i in range(len(nums)):
            if nodes[i]:
                nodes[i].left = nodes[idx]
                idx += 1

                nodes[i].right = nodes[idx]
                idx += 1
        return nodes[0]

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
# @lc code=end

