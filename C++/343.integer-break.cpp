/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (49.21%)
 * Likes:    788
 * Dislikes: 200
 * Total Accepted:    95.4K
 * Total Submissions: 193.7K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */

#include<vector>
#include<math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for (int i=3; i <= n; ++i) {
            for (int j=1; j<i; ++j) {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    
        if (n==2 || n == 3)
            return n - 1;
        if (n%3 == 0)
            return pow(3, n/3);
        if (n%3==1)
            return pow(3, n/3-1) * 4;
        if(n%3 == 2)
            return pow(3, n/3) * 2;
    }
};
// @lc code=end

