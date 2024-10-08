/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (55.02%)
 * Likes:    2245
 * Dislikes: 205
 * Total Accepted:    207.9K
 * Total Submissions: 377.9K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) 
            nums[(nums[i]-1) % n] += n;
        vector<int> res;
        for (int i=0; i <n; i++) 
            if (nums[i]<=n) 
                res.push_back(i+1);
        return res;


        for (int i=0; i<nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) 
                nums[idx] = -nums[idx];
        }
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > 0) ans.push_back(i+1);
        }
        return ans;


        // for (int i=0; i<nums.size(); i++) {
        //     while (true) {
        //         if (nums[i]==i+1 || nums[i]==nums[nums[i]-1])
        //             break;
        //         swap(nums[i], nums[nums[i]-1]);
        //     }
        // }
        for(int i=0; i<nums.size(); ++ i)
            while(nums[nums[i]-1]!=nums[i])
                swap(nums[i], nums[nums[i]-1]);

        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=(i+1)) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
// @lc code=end

