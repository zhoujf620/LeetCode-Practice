#
# @lc app=leetcode id=33 lang=python
#
# [33] Search in Rotated Sorted Array
#
# https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#
# algorithms
# Medium (33.31%)
# Likes:    3159
# Dislikes: 371
# Total Accepted:    506.9K
# Total Submissions: 1.5M
# Testcase Example:  '[4,5,6,7,0,1,2]\n0'
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown
# to you beforehand.
# 
# (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
# 
# You are given a target value to search. If found in the array return its
# index, otherwise return -1.
# 
# You may assume no duplicate exists in the array.
# 
# Your algorithm's runtime complexity must be in the order of O(log n).
# 
# Example 1:
# 
# 
# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4
# 
# 
# Example 2:
# 
# 
# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1
# 
#

# @lc code=start
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # left, right = 0, len(nums) - 1
        # while left < right:
        #     mid = left + (right - left) // 2
        #     if nums[mid] > nums[right]:
        #         left = mid + 1
        #     else:
        #         right = mid
        
        # rot = left
        # n = len(nums)
        # left, right = 0, len(nums) - 1
        # while left <= right:
        #     mid = left + (right - left) // 2
        #     roted_idx = (mid + rot) % n
        #     if nums[roted_idx] == target:
        #         return roted_idx
        #     elif nums[roted_idx] < target:
        #         left = mid + 1
        #     else:
        #         right = mid - 1
        # return -1

        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if target == nums[mid]:
                return mid
            
            # left part is sorted
            if nums[left] <= nums[mid]:
                if nums[left] <= target and target <=nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            
            # right part is sorted
            else:
                if nums[mid] <= target and target <= nums[right]:
                    left = mid + 1  
                else:
                    right = mid - 1
        return -1


# @lc code=end

sol = Solution()
# nums =[4,5,6,7,0,1,2]
nums = [4,5,6,7,0,1,2]
target = 1
print(sol.search(nums, target))