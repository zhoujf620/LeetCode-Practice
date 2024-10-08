/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 *
 * https://leetcode.com/problems/count-sorted-vowel-strings/description/
 *
 * algorithms
 * Medium (77.36%)
 * Likes:    3443
 * Dislikes: 73
 * Total Accepted:    155.1K
 * Total Submissions: 200.4K
 * Testcase Example:  '1'
 *
 * Given an integer n, return the number of strings of length n that consist
 * only of vowels (a, e, i, o, u) and are lexicographically sorted.
 * 
 * A string s is lexicographically sorted if for all valid i, s[i] is the same
 * as or comes before s[i+1] in the alphabet.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: 5
 * Explanation: The 5 sorted strings that consist of vowels only are
 * ["a","e","i","o","u"].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: 15
 * Explanation: The 15 sorted strings that consist of vowels only are
 * 
 * ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
 * Note that "ea" is not a valid string since 'e' comes after 'a' in the
 * alphabet.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 33
 * Output: 66045
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 50 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        for (int i=2; i<=n; ++i) {
            dp[4] = dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
            dp[3] = dp[0] + dp[1] + dp[2] + dp[3];
            dp[2] = dp[0] + dp[1] + dp[2];
            dp[1] = dp[0] + dp[1];
            dp[0] = dp[0];
        }
        return dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
    }
};
// @lc code=end

