/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (45.23%)
 * Likes:    581
 * Dislikes: 105
 * Total Accepted:    88.8K
 * Total Submissions: 196.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the length of longest continuous
 * increasing subsequence (subarray).
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 3
 * Explanation: The longest continuous increasing subsequence is [1,3,5], its
 * length is 3. 
 * Even though [1,3,5,7] is also an increasing subsequence, it's not a
 * continuous one where 5 and 7 are separated by 4. 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 1
 * Explanation: The longest continuous increasing subsequence is [2], its
 * length is 1. 
 * 
 * 
 * 
 * Note:
 * Length of the array will not exceed 10,000.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        // vector<int> dp(nums.size(), 1);
        // for (int i=1; i<nums.size(); i++) {
        //     if (nums[i]>nums[i-1]) 
        //         dp[i] = dp[i-1] + 1;
        // }
        // return *max_element(dp.begin(), dp.end());

        if (nums.empty()) return 0;
        
        int ans=1, cur=1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > nums[i-1])
                ans = max(ans, ++cur);
            else 
                cur = 1;
        }
        return ans;
    }
};
// @lc code=end

