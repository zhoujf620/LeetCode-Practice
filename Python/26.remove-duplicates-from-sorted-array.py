#
# @lc app=leetcode id=26 lang=python
#
# [26] Remove Duplicates from Sorted Array
#
# https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#
# algorithms
# Easy (42.26%)
# Likes:    1792
# Dislikes: 3897
# Total Accepted:    721.2K
# Total Submissions: 1.7M
# Testcase Example:  '[1,1,2]'
#
# Given a sorted array nums, remove the duplicates in-place such that each
# element appear only once and return the new length.
# 
# Do not allocate extra space for another array, you must do this by modifying
# the input array in-place with O(1) extra memory.
# 
# Example 1:
# 
# 
# Given nums = [1,1,2],
# 
# Your function should return length = 2, with the first two elements of nums
# being 1 and 2 respectively.
# 
# It doesn't matter what you leave beyond the returned length.
# 
# Example 2:
# 
# 
# Given nums = [0,0,1,1,1,2,2,3,3,4],
# 
# Your function should return length = 5, with the first five elements of nums
# being modified to 0, 1, 2, 3, and 4 respectively.
# 
# It doesn't matter what values are set beyond the returned length.
# 
# 
# Clarification:
# 
# Confused why the returned value is an integer but your answer is an array?
# 
# Note that the input array is passed in by reference, which means modification
# to the input array will be known to the caller as well.
# 
# Internally you can think of this:
# 
# 
# // nums is passed in by reference. (i.e., without making a copy)
# int len = removeDuplicates(nums);
# 
# // any modification to nums in your function would be known by the caller.
# // using the length returned by your function, it prints the first len
# elements.
# for (int i = 0; i < len; i++) {
# print(nums[i]);
# }
#

# @lc code=start
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # i, j = 0, 1 
        # # for i in range(len(nums)):
        # while i < len(nums):
        #     while i < len(nums) - 1: 
        #         if nums[i] == nums[i+1]:
        #             i += 1 
        #         else:
        #             nums[j] = nums[i+1]
        #             j = j+1
        #             break
        #     i += 1
        # return j 

        i = 0 
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        return i+1

        idx = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[idx-1]:
                nums[idx] = nums[i]
                idx += 1
        return idx
    
# @lc code=end

sol = Solution()
nums = [0,0,1,1,1,2,2,3,3,4]
sol.removeDuplicates(nums)
print(nums)