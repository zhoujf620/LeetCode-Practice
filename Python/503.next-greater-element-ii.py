#
# @lc app=leetcode id=503 lang=python
#
# [503] Next Greater Element II
#
# https://leetcode.com/problems/next-greater-element-ii/description/
#
# algorithms
# Medium (52.59%)
# Likes:    889
# Dislikes: 53
# Total Accepted:    64.4K
# Total Submissions: 122K
# Testcase Example:  '[1,2,1]'
#
# 
# Given a circular array (the next element of the last element is the first
# element of the array), print the Next Greater Number for every element. The
# Next Greater Number of a number x is the first greater number to its
# traversing-order next in the array, which means you could search circularly
# to find its next greater number. If it doesn't exist, output -1 for this
# number.
# 
# 
# Example 1:
# 
# Input: [1,2,1]
# Output: [2,-1,2]
# Explanation: The first 1's next greater number is 2; The number 2 can't find
# next greater number; The second 1's next greater number needs to search
# circularly, which is also 2.
# 
# 
# 
# Note:
# The length of given array won't exceed 10000.
# 
#

# @lc code=start
class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        res = [-1 for _ in range(len(nums))]
        n = len(nums)
        stack = []
        for i in range(n * 2):
            while stack and nums[i%n] > nums[stack[-1]]:
                cur = stack.pop()
                res[cur] = nums[i%n]
            if i < n:
                stack.append(i)
        return res 
# @lc code=end

sol = Solution()
nums = [1,2,1]
print(sol.nextGreaterElements(nums))