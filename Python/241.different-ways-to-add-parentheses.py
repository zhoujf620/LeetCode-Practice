#
# @lc app=leetcode id=241 lang=python
#
# [241] Different Ways to Add Parentheses
#
# https://leetcode.com/problems/different-ways-to-add-parentheses/description/
#
# algorithms
# Medium (52.10%)
# Likes:    1219
# Dislikes: 61
# Total Accepted:    86K
# Total Submissions: 164.3K
# Testcase Example:  '"2-1-1"'
#
# Given a string of numbers and operators, return all possible results from
# computing all the different possible ways to group numbers and operators. The
# valid operators are +, - and *.
# 
# Example 1:
# 
# 
# Input: "2-1-1"
# Output: [0, 2]
# Explanation: 
# ((2-1)-1) = 0 
# (2-(1-1)) = 2
# 
# Example 2:
# 
# 
# Input: "2*3-4*5"
# Output: [-34, -14, -10, -10, 10]
# Explanation: 
# (2*(3-(4*5))) = -34 
# ((2*3)-(4*5)) = -14 
# ((2*(3-4))*5) = -10 
# (2*((3-4)*5)) = -10 
# (((2*3)-4)*5) = 10
# 
#

# @lc code=start
class Solution(object):
    def diffWaysToCompute(self, s):
        """
        :type input: str
        :rtype: List[int]
        """
        return self.dfs(s)

    def dfs(self, s):
        if s.isdigit():
            return [int(s)]

        ans = []
        for i in range(len(s)):
            if s[i] in ['+', '-', '*']:
                left_vals = self.dfs(s[:i])
                right_vals = self.dfs(s[i+1:])
                for l in left_vals:
                    for r in right_vals:
                        ans.append(self.cal(l, r, s[i]))
        return ans
    
    def cal(self, num1, num2, op):
        if op == '+':
            return num1 + num2
        if op == '-':
            return num1 - num2
        if op == '*':
            return num1 * num2
# @lc code=end

sol = Solution()
s = "2-1-1"
print(sol.diffWaysToCompute(s))