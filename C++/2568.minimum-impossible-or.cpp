/*
 * @lc app=leetcode id=2568 lang=cpp
 *
 * [2568] Minimum Impossible OR
 *
 * https://leetcode.com/problems/minimum-impossible-or/description/
 *
 * algorithms
 * Medium (54.05%)
 * Likes:    192
 * Dislikes: 8
 * Total Accepted:    9.7K
 * Total Submissions: 17.4K
 * Testcase Example:  '[2,1]'
 *
 * You are given a 0-indexed integer array nums.
 * 
 * We say that an integer x is expressible from nums if there exist some
 * integers 0 <= index1 < index2 < ... < indexk < nums.length for which
 * nums[index1] | nums[index2] | ... | nums[indexk] = x. In other words, an
 * integer is expressible if it can be written as the bitwise OR of some
 * subsequence of nums.
 * 
 * Return the minimum positive non-zero integer that is not expressible from
 * nums.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,1]
 * Output: 4
 * Explanation: 1 and 2 are already present in the array. We know that 3 is
 * expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not
 * expressible, we return 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,3,2]
 * Output: 1
 * Explanation: We can show that 1 is the smallest number that is not
 * expressible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> hset(nums.begin(), nums.end());
        int num = 1;
        whlie (hset.count(num)) {
            num <<= 1;
        }
        return num;
    }
};
// @lc code=end

