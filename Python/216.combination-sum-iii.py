#
# @lc app=leetcode id=216 lang=python
#
# [216] Combination Sum III
#
# https://leetcode.com/problems/combination-sum-iii/description/
#
# algorithms
# Medium (53.51%)
# Likes:    759
# Dislikes: 41
# Total Accepted:    140.8K
# Total Submissions: 262.3K
# Testcase Example:  '3\n7'
#
# 
# Find all possible combinations of k numbers that add up to a number n, given
# that only numbers from 1 to 9 can be used and each combination should be a
# unique set of numbers.
# 
# Note:
# 
# 
# All numbers will be positive integers.
# The solution set must not contain duplicate combinations.
# 
# 
# Example 1:
# 
# 
# Input: k = 3, n = 7
# Output: [[1,2,4]]
# 
# 
# Example 2:
# 
# 
# Input: k = 3, n = 9
# Output: [[1,2,6], [1,3,5], [2,3,4]]
# 
# 
#

# @lc code=start
class Solution(object):
    def combinationSum3(self, k, target):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """

        res = []
        self.dfs(1, k, target, [], res)
        return res

    def dfs(self, index, k, target, path, res):
        if target < 0 or k<0:
            return
        elif target == 0 and k==0:
            res.append(path)
        else:
            for i in range(index, 10):
                self.dfs(i+1, k-1, target-i, path+[i], res)
        
# @lc code=end

