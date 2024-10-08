/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (51.93%)
 * Likes:    2620
 * Dislikes: 67
 * Total Accepted:    102.2K
 * Total Submissions: 196.1K
 * Testcase Example:  '[3,1,5,8]'
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 * 
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 * Note:
 * 
 * 
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 * not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * Example:
 * 
 * 
 * Input: [3,1,5,8]
 * Output: 167 
 * Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  -->
 * []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // divide and conquer, reverse thinking
        // divide the problem by the last balloon to burst.
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int len=1; len<=n; ++len) {
            for (int i=1; i<=n-len+1; ++i) {
                int j = i+len-1;
                for (int k=i; k<=j; ++k) {
                    dp[i][j] = max(dp[i][j], 
                                   nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

