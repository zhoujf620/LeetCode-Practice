/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (38.05%)
 * Likes:    3348
 * Dislikes: 180
 * Total Accepted:    454.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string> dicts(wordDict.begin(), wordDict.end());
        int n = str.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i=0; i<n; i++) {
            for (int len=0; len<n-i+1; len++) {
                if (dp[i] && dicts.count(str.substr(i, len)))
                    dp[i+len] = true;
            }
        }
        return dp[n];

        // dict 中的单词没有使用次数的限制，因此这是一个完全背包问题。求解顺序的完全背包问题时，对物品的迭代应该放在最里层，对背包的迭代放在外层，只有这样才能让物品按一定顺序放入背包中。
        int n = str.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i=1; i<=n; i++) {
            for (string word: wordDict) {
                int len = word.size();
                if (i>=len && str.substr(i-len, len)==word)
                    dp[i] = dp[i] || dp[i-len];
            }
        }
        return dp[n];
    }
};
// @lc code=end

