#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#
# https://leetcode.com/problems/permutation-in-string/description/
#
# algorithms
# Medium (44.40%)
# Likes:    11229
# Dislikes: 405
# Total Accepted:    868.3K
# Total Submissions: 2M
# Testcase Example:  '"ab"\n"eidbaooo"'
#
# Given two strings s1 and s2, return true if s2 contains a permutation of s1,
# or false otherwise.
# 
# In other words, return true if one of s1's permutations is the substring of
# s2.
# 
# 
# Example 1:
# 
# 
# Input: s1 = "ab", s2 = "eidbaooo"
# Output: true
# Explanation: s2 contains one permutation of s1 ("ba").
# 
# 
# Example 2:
# 
# 
# Input: s1 = "ab", s2 = "eidboaoo"
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s1.length, s2.length <= 10^4
# s1 and s2 consist of lowercase English letters.
# 
# 
#

# @lc code=start
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        n1, n2 = len(s1), len(s2)
        if n1 > n2:
            return False

        cnts1 = collections.Counter(s1)
        cnts2 = collections.Counter()
        for i in range(n1):
            cnts2[s2[i]] += 1
        if cnts1 == cnts2:
            return True
        
        for i in range(n1, n2):
            cnts2[s2[i]] += 1
            cnts2[s2[i-n1]] -= 1
            if cnts1 == cnts2:
                return True
        return False

        

# @lc code=end

