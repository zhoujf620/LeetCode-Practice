#
# @lc app=leetcode id=587 lang=python
#
# [587] Erect the Fence
#
# https://leetcode.com/problems/erect-the-fence/description/
#
# algorithms
# Hard (34.67%)
# Likes:    154
# Dislikes: 162
# Total Accepted:    7.8K
# Total Submissions: 22.5K
# Testcase Example:  '[[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]'
#
# There are some trees, where each tree is represented by (x,y) coordinate in a
# two-dimensional garden. Your job is to fence the entire garden using the
# minimum length of rope as it is expensive. The garden is well fenced only if
# all the trees are enclosed. Your task is to help find the coordinates of
# trees which are exactly located on the fence perimeter.
# 
# 
# 
# Example 1:
# 
# 
# Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
# Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
# Explanation:
# 
# 
# 
# Example 2:
# 
# 
# Input: [[1,2],[2,2],[4,2]]
# Output: [[1,2],[2,2],[4,2]]
# Explanation:
# 
# Even you only have trees in a line, you need to use rope to enclose
# them. 
# 
# 
# 
# 
# Note:
# 
# 
# All trees should be enclosed together. You cannot cut the rope to enclose
# trees that will separate them in more than one group.
# All input integers will range from 0 to 100.
# The garden has at least one tree.
# All coordinates are distinct.
# Input points have NO order. No order required for output.
# input types have been changed on April 15, 2019. Please reset to default code
# definition to get new method signature.
# 
# 
#

# @lc code=start
class Solution(object):
    def outerTrees(self, points):
        """
        :type points: List[List[int]]
        :rtype: List[List[int]]
        """
        
# @lc code=end

