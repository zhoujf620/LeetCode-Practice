/*
 * @lc app=leetcode id=651 lang=cpp
 *
 * [651] 4 Keys Keyboard
 *
 * Imagine you have a special keyboard with the following keys:
 * 
 * Key 1: (A): Print one 'A' on screen.
 * 
 * Key 2: (Ctrl-A): Select the whole screen.
 * 
 * Key 3: (Ctrl-C): Copy selection to buffer.
 * 
 * Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
 * 
 * Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.
 * 
 * Example 1:
 * 
 * Input: N = 3
 * Output: 3
 * Explanation: 
 * We can at most get 3 A's on screen by pressing following key sequence:
 * A, A, A
 * 
 * Example 2:
 * Input: N = 7
 * Output: 9
 * Explanation: 
 * We can at most get 9 A's on screen by pressing following key sequence:
 * A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
 * 
 * Note:
 * 1 <= N <= 50
 * Answers will be in the range of 32-bit signed integer.
 * 
 * 
 * 
 */
#include<vector>
#include<math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1, 0);
        for (int i = 0; i <= N; ++i) {
            dp[i] = i;
            for (int j=1; j<i-2; ++j) {
                dp[i] = max(dp[i], dp[j] * (i-j-1));
            }
        }
        return dp[N];
    }
};
// @lc code=end

