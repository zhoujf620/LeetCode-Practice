/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (41.55%)
 * Likes:    682
 * Dislikes: 924
 * Total Accepted:    173.3K
 * Total Submissions: 416.4K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        sums.resize(nums.size()+1, 0);

        for (int i=0; i<nums.size(); i++) 
            sums[i+1] = nums[i]+sums[i];
    }
    
    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

