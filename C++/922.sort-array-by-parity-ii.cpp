/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 *
 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (67.91%)
 * Likes:    453
 * Dislikes: 41
 * Total Accepted:    73.9K
 * Total Submissions: 108.9K
 * Testcase Example:  '[4,2,5,7]'
 *
 * Given an array A of non-negative integers, half of the integers in A are
 * odd, and half of the integers are even.
 * 
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is
 * even, i is even.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been
 * accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0, j=1;
        while (i<nums.size() && j<nums.size()) {
            if(nums[i]%2==1 && nums[j]%2==0) {
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
            if (i<nums.size() && nums[i]%2==0)
                i += 2;
            if (j<nums.size() && nums[j]%2==1)
                j += 2;
        }
        return nums;
    }
};
// @lc code=end

