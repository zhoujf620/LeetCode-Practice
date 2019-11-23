#
# @lc app=leetcode id=474 lang=python
#
# [474] Ones and Zeroes
#
# https://leetcode.com/problems/ones-and-zeroes/description/
#
# algorithms
# Medium (40.91%)
# Likes:    677
# Dislikes: 160
# Total Accepted:    36.9K
# Total Submissions: 90.1K
# Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
#
# In the computer world, use restricted resource you have to generate maximum
# benefit is what we always want to pursue.
# 
# For now, suppose you are a dominator of m 0s and n 1s respectively. On the
# other hand, there is an array with strings consisting of only 0s and 1s.
# 
# Now your task is to find the maximum number of strings that you can form with
# given m 0s and n 1s. Each 0 and 1 can be used at most once.
# 
# Note:
# 
# 
# The given numbers of 0s and 1s will both not exceed 100
# The size of given string array won't exceed 600.
# 
# 
# 
# 
# Example 1:
# 
# 
# Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
# Output: 4
# 
# Explanation: This are totally 4 strings can be formed by the using of 5 0s
# and 3 1s, which are “10,”0001”,”1”,”0”
# 
# 
# 
# 
# Example 2:
# 
# 
# Input: Array = {"10", "0", "1"}, m = 1, n = 1
# Output: 2
# 
# Explanation: You could form "10", but then you'd have nothing left. Better
# form "0" and "1".
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        # 这是一个多维费用的 0-1 背包问题，有两个背包大小，0 的数量和 1 的数量。

        def count(s):
            ones, zeros = 0, 0 
            for c in s:
                if c=='0':
                    zeros+=1
                else:
                    ones += 1
            return zeros, ones

        if not strs:
            return 0 
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for s in strs:
            zeros, ones= count(s)
            
            for i in range(m, zeros-1, -1):
                for j in range(n, ones-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1)
        return dp[m][n]
# @lc code=end

