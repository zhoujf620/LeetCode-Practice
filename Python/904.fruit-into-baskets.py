#
# @lc app=leetcode id=904 lang=python3
#
# [904] Fruit Into Baskets
#
# https://leetcode.com/problems/fruit-into-baskets/description/
#
# algorithms
# Medium (44.31%)
# Likes:    4595
# Dislikes: 337
# Total Accepted:    405.4K
# Total Submissions: 914.6K
# Testcase Example:  '[1,2,1]'
#
# You are visiting a farm that has a single row of fruit trees arranged from
# left to right. The trees are represented by an integer array fruits where
# fruits[i] is the type of fruit the i^th tree produces.
# 
# You want to collect as much fruit as possible. However, the owner has some
# strict rules that you must follow:
# 
# 
# You only have two baskets, and each basket can only hold a single type of
# fruit. There is no limit on the amount of fruit each basket can hold.
# Starting from any tree of your choice, you must pick exactly one fruit from
# every tree (including the start tree) while moving to the right. The picked
# fruits must fit in one of your baskets.
# Once you reach a tree with fruit that cannot fit in your baskets, you must
# stop.
# 
# 
# Given the integer array fruits, return the maximum number of fruits you can
# pick.
# 
# 
# Example 1:
# 
# 
# Input: fruits = [1,2,1]
# Output: 3
# Explanation: We can pick from all 3 trees.
# 
# 
# Example 2:
# 
# 
# Input: fruits = [0,1,2,2]
# Output: 3
# Explanation: We can pick from trees [1,2,2].
# If we had started at the first tree, we would only pick from trees [0,1].
# 
# 
# Example 3:
# 
# 
# Input: fruits = [1,2,3,2,2]
# Output: 4
# Explanation: We can pick from trees [2,3,2,2].
# If we had started at the first tree, we would only pick from trees [1,2].
# 
# 
# 
# Constraints:
# 
# 
# 1 <= fruits.length <= 10^5
# 0 <= fruits[i] < fruits.length
# 
# 
#

# @lc code=start
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # maximum length of a subarray with at most 2 distinct elements
        
        left, right = 0, 0
        count = {}
        ans = 0
        while right < len(fruits):
            count[fruits[right]] = count.get(fruits[right], 0) + 1
            while len(count) > 2:
                count[fruits[left]] -= 1
                if count[fruits[left]] == 0:
                    del count[fruits[left]]
                left += 1
            ans = max(ans, right - left + 1)
            right += 1
        return ans
        
# @lc code=end

