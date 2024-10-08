#
# @lc app=leetcode id=139 lang=python
#
# [139] Word Break
#
# https://leetcode.com/problems/word-break/description/
#
# algorithms
# Medium (37.11%)
# Likes:    2924
# Dislikes: 164
# Total Accepted:    413.9K
# Total Submissions: 1.1M
# Testcase Example:  '"leetcode"\n["leet","code"]'
#
# Given a non-empty string s and a dictionary wordDict containing a list of
# non-empty words, determine if s can be segmented into a space-separated
# sequence of one or more dictionary words.
# 
# Note:
# 
# 
# The same word in the dictionary may be reused multiple times in the
# segmentation.
# You may assume the dictionary does not contain duplicate words.
# 
# 
# Example 1:
# 
# 
# Input: s = "leetcode", wordDict = ["leet", "code"]
# Output: true
# Explanation: Return true because "leetcode" can be segmented as "leet
# code".
# 
# 
# Example 2:
# 
# 
# Input: s = "applepenapple", wordDict = ["apple", "pen"]
# Output: true
# Explanation: Return true because "applepenapple" can be segmented as "apple
# pen apple".
# Note that you are allowed to reuse a dictionary word.
# 
# 
# Example 3:
# 
# 
# Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
# Output: false
# 
# 
#

# @lc code=start
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """

        # if s == "":
        #     return True 

        # for i in range(len(s)):
        #     if s[0:i+1] in wordDict:
        #         if self.wordBreak(s[i+1:], wordDict):
        #         if dp[i+1]: # top-down
        #             return True
        # return False

        # dp[i] means s[:i+1] can be segmented into words in the wordDicts 
        # dp = brute force + memoization
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(len(s)):
            for j in range(i, len(s)):
                if dp[i] and s[i: j+1] in wordDict:
                    dp[j+1] = True
                    
        return dp[-1]

        # dict 中的单词没有使用次数的限制，因此这是一个完全背包问题。
        # 求解顺序的完全背包问题时，对物品的迭代应该放在最里层，对背包的迭代放在外层，只有这样才能让物品按一定顺序放入背包中。

        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(1, len(s)+1):
            for word in wordDict:
                l = len(word)
                if l <= i and word == s[i-l:i]:
                    dp[i] = dp[i] or dp[i-l]
        return dp[-1]

# @lc code=end

sol = Solution()
s = 'leetcode'
wordDict = ["leet", "code"]
print(sol.wordBreak(s, wordDict))