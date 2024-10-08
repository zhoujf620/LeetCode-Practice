/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 *
 * https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (49.65%)
 * Likes:    366
 * Dislikes: 25
 * Total Accepted:    22.1K
 * Total Submissions: 44.5K
 * Testcase Example:  '1\n6\n3'
 *
 * You have d dice, and each die has f faces numbered 1, 2, ..., f.
 * 
 * Return the number of possible ways (out of f^d total ways) modulo 10^9 + 7
 * to roll the dice so the sum of the face up numbers equals target.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: d = 1, f = 6, target = 3
 * Output: 1
 * Explanation: 
 * You throw one die with 6 faces.  There is only one way to get a sum of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: d = 2, f = 6, target = 7
 * Output: 6
 * Explanation: 
 * You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
 * 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: d = 2, f = 5, target = 10
 * Output: 1
 * Explanation: 
 * You throw two dice, each with 5 faces.  There is only one way to get a sum
 * of 10: 5+5.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: d = 1, f = 2, target = 3
 * Output: 0
 * Explanation: 
 * You throw one die with 2 faces.  There is no way to get a sum of 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: d = 30, f = 30, target = 500
 * Output: 222616187
 * Explanation: 
 * The answer must be returned modulo 10^9 + 7.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= d, f <= 30
 * 1 <= target <= 1000
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numRollsToTarget(int n, int m, int target) {
        // // dp[i][k]=sum(dp[i−1][k-j] for 0<j<f)

        // int mode = 1e9+7;
        // vector<int> dp(target+1, 0);
        // dp[0] = 1;
        
        // for (int i=1; i<=d; ++i) {
            
        //     vector<int> cur(target + 1);
        //     for (int j=1; j<=f; ++j)
        //           for (int k=target; k>=j; k--)
        //                 cur[k] = (cur[k] + dp[k-j]) % mode;

        //     swap(dp, cur);
        // }
        // return dp[target];

        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        
        for (int i=1; i<=n; ++i) {
            for (int j=i; j<=target; ++j) {
                for (int k=1; k<=m && k<=j; ++k) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;
                }
            }
        }
        return dp[n][target];


        int mod = 1e9+7;
        
        vector<int> dp(target+1, 0);
        dp[0] = 1;
            
        for (int i=1; i<=n; ++i) {
            vector<int> tmp(target+1, 0); // [i][j], [i-1][j] are different
            for (int j=i; j<=target; ++j) {
                for (int k=1; k<=m && k<=j; ++k) {
                    tmp[j] = (tmp[j] + dp[j-k]) % mod;
                }
            }
            dp = tmp;
        }
        return dp[target];
    }
};
// @lc code=end

