/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 *
 * https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (58.37%)
 * Likes:    425
 * Dislikes: 6
 * Total Accepted:    13.7K
 * Total Submissions: 23.5K
 * Testcase Example:  '"zzazz"'
 *
 * Given a string s. In one step you can insert any character at any index of
 * the string.
 * 
 * Return the minimum number of steps to make s palindrome.
 * 
 * A Palindrome String is one that reads the same backward as well as
 * forward.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we don't need any
 * insertions.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "g"
 * Output: 0
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "no"
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * All characters of s are lower case English letters.
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len=2; len<=n; ++len) {
            for (int i=0; i<n-len+1; ++i) {
                int j = i+len - 1;
                
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                if (s[i] == s[j]) {
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

