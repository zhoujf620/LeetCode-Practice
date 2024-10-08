/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 *
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * algorithms
 * Medium (56.95%)
 * Likes:    618
 * Dislikes: 1791
 * Total Accepted:    90.6K
 * Total Submissions: 159.1K
 * Testcase Example:  '10'
 *
 * An integer x is a good if after rotating each digit individually by 180
 * degrees, we get a valid number that is different from x. Each digit must be
 * rotated - we cannot choose to leave it alone.
 * 
 * A number is valid if each digit remains a digit after rotation. For
 * example:
 * 
 * 
 * 0, 1, and 8 rotate to themselves,
 * 2 and 5 rotate to each other (in this case they are rotated in a different
 * direction, in other words, 2 or 5 gets mirrored),
 * 6 and 9 rotate to each other, and
 * the rest of the numbers do not rotate to any other number and become
 * invalid.
 * 
 * 
 * Given an integer n, return the number of good integers in the range [1,
 * n].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10
 * Output: 4
 * Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after
 * rotating.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 2
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        
        vector<int> flags{1,1,2,0,0,2,2,0,1,2};
        for (int i=1; i<=n; ++i) {
            int num = i, tmp = 1;
            while (num) {
                tmp *= flags[num % 10];
                num /= 10;
            }
            
            if (tmp > 1) ans += 1;
        }
        return ans;
    }
};
// @lc code=end

