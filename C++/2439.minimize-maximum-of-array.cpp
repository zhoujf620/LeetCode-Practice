/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 *
 * https://leetcode.com/problems/minimize-maximum-of-array/description/
 *
 * algorithms
 * Medium (34.36%)
 * Likes:    1490
 * Dislikes: 369
 * Total Accepted:    40.8K
 * Total Submissions: 92.4K
 * Testcase Example:  '[3,7,1,6]'
 *
 * You are given a 0-indexed array nums comprising of n non-negative integers.
 * 
 * In one operation, you must:
 * 
 * 
 * Choose an integer i such that 1 <= i < n and nums[i] > 0.
 * Decrease nums[i] by 1.
 * Increase nums[i - 1] by 1.
 * 
 * 
 * Return the minimum possible value of the maximum integer of nums after
 * performing any number of operations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,7,1,6]
 * Output: 5
 * Explanation:
 * One set of optimal operations is as follows:
 * 1. Choose i = 1, and nums becomes [4,6,1,6].
 * 2. Choose i = 3, and nums becomes [4,6,2,5].
 * 3. Choose i = 1, and nums becomes [5,5,2,5].
 * The maximum integer of nums is 5. It can be shown that the maximum number
 * cannot be less than 5.
 * Therefore, we return 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [10,1]
 * Output: 10
 * Explanation:
 * It is optimal to leave nums as is, and since 10 is the maximum value, we
 * return 10.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 2 <= n <= 10^5
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        // average 
        long sum = 0, ans = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            ans = max(ans, (sum+i)/(i+1));
        }
        return ans;



        int left = 0, right = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (helper(nums, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    bool helper(vector<int>& nums, int mx) {
        long need = 0;
        for (int num : nums) {
            if (num-mx > need) return false;
            need += (mx - num);
        }
        return true;
    }
};
// @lc code=end

