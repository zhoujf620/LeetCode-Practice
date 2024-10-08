/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (53.74%)
 * Likes:    1045
 * Dislikes: 54
 * Total Accepted:    72.7K
 * Total Submissions: 135.3K
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        vector<int> monostack;
        for (int i=0; i<n*2; i++) {
            while (!monostack.empty() && nums[i%n]>nums[monostack.back()]) {
                res[monostack.back()] = nums[i%n];
                monostack.pop_back();
            }
            monostack.push_back(i%n);
        }
        return res;
    }
};
// @lc code=end

