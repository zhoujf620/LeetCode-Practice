/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 *
 * https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/
 *
 * algorithms
 * Medium (52.44%)
 * Likes:    394
 * Dislikes: 232
 * Total Accepted:    36.6K
 * Total Submissions: 69.2K
 * Testcase Example:  '1'
 *
 * Given an integer n, return the decimal value of the binary string formed by
 * concatenating the binary representations of 1 to n in order, modulo 10^9 +
 * 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * Explanation: "1" in binary corresponds to the decimal value 1. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: 27
 * Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
 * After concatenating them, we have "11011", which corresponds to the decimal
 * value 27.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 12
 * Output: 505379714
 * Explanation: The concatenation results in
 * "1101110010111011110001001101010111100".
 * The decimal value of that is 118505380540.
 * After modulo 10^9 + 7, the result is 505379714.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, offset = 0, mod=1e9+7;
        for (long i=1; i<=n; ++i) {
            if ((i&(i-1)) == 0) offset += 1;
            ans = ((ans << offset) | i) % mod;
        }
        return ans;
    }
};
// @lc code=end

