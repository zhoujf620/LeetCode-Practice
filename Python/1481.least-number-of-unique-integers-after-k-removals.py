#
# @lc app=leetcode id=1481 lang=python3
#
# [1481] Least Number of Unique Integers after K Removals
#
# https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
#
# algorithms
# Medium (63.05%)
# Likes:    2239
# Dislikes: 226
# Total Accepted:    248K
# Total Submissions: 393.3K
# Testcase Example:  '[5,5,4]\n1'
#
# Given an array of integers arr and an integer k. Find the least number of
# unique integers after removing exactly k elements.
# 
# 
# 
# 
# 
# Example 1:
# 
# 
# Input: arr = [5,5,4], k = 1
# Output: 1
# Explanation: Remove the single 4, only 5 is left.
# 
# Example 2:
# 
# 
# Input: arr = [4,3,1,1,3,3,2], k = 3
# Output: 2
# Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3
# will be left.
# 
# 
# Constraints:
# 
# 
# 1 <= arr.length <= 10^5
# 1 <= arr[i] <= 10^9
# 0 <= k <= arr.length
# 
#

# @lc code=start
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        cnts = Counter(arr)
        freqs = cnts.values()

        ans = len(freqs)
        for f in sorted(freqs):
            if f <= k:
                ans -= 1
                k -= f
            else:
                break
        return ans
# @lc code=end

