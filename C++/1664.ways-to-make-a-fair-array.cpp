/*
 * @lc app=leetcode id=1664 lang=cpp
 *
 * [1664] Ways to Make a Fair Array
 *
 * https://leetcode.com/problems/ways-to-make-a-fair-array/description/
 *
 * algorithms
 * Medium (63.35%)
 * Likes:    1094
 * Dislikes: 30
 * Total Accepted:    29.3K
 * Total Submissions: 46.3K
 * Testcase Example:  '[2,1,6,4]'
 *
 * You are given an integer array nums. You can choose exactly one index
 * (0-indexed) and remove the element. Notice that the index of the elements
 * may change after the removal.
 * 
 * For example, if nums = [6,1,7,4,1]:
 * 
 * 
 * Choosing to remove index 1 results in nums = [6,7,4,1].
 * Choosing to remove index 2 results in nums = [6,1,4,1].
 * Choosing to remove index 4 results in nums = [6,1,7,4].
 * 
 * 
 * An array is fair if the sum of the odd-indexed values equals the sum of the
 * even-indexed values.
 * 
 * Return the number of indices that you could choose such that after the
 * removal, nums is fair. 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,1,6,4]
 * Output: 1
 * Explanation:
 * Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
 * Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
 * Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
 * Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
 * There is 1 index that you can remove to make nums fair.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1]
 * Output: 3
 * Explanation: You can remove any index and the remaining array is fair.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 0
 * Explanation: You cannot make a fair array after removing any index.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 1;
        if (n==2) return 0;

        vector<int> preSum(n, 0);
        preSum[0] = nums[0], preSum[1] = nums[1];
        for (int i=2; i<n; ++i) preSum[i] = preSum[i-2] + nums[i];
    
        vector<int> revSum(n, 0);
        revSum[n-1] = nums[n-1], revSum[n-2] = nums[n-2];
        for (int i=n-3; i>=0; --i) revSum[i] = revSum[i+2] + nums[i];

        int ans = 0;
        for (int i=0; i<n; ++i) {
            int diff1 = 0;
            if (i==0) diff1 = 0;
            else if (i==1) diff1 = preSum[0];
            else diff1 = preSum[i-1] - preSum[i-2];

            int diff2 = 0;
            if (i==n-1) diff2 = 0;
            else if (i==n-2) diff2 = revSum[n-1];
            else diff2 =  revSum[i+1] - revSum[i+2];

            if (diff1 == diff2) ans += 1;
        }
        return ans;

        int res = 0, n = A.size(), left[2] = {}, right[2] = {};
        for (int i = 0; i < n; ++i)
            right[i % 2] += A[i];
        for (int i = 0; i < n; ++i) {
            right[i % 2] -= A[i];
            res += left[0] + right[1] == left[1] + right[0];
            left[i % 2] += A[i];
        }
        return res;

    }
};
// @lc code=end

