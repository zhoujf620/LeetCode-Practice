/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (41.46%)
 * Likes:    527
 * Dislikes: 273
 * Total Accepted:    62.1K
 * Total Submissions: 149.8K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 
 * The set S originally contains numbers from 1 to n. But unfortunately, due to
 * the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number. 
 * 
 * 
 * 
 * Given an array nums representing the data status of this set after the
 * error. Your task is to firstly find the number occurs twice and then find
 * the number that is missing. Return them in the form of an array.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * 
 * 
 * 
 * Note:
 * 
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            while(nums[nums[i]-1]!=nums[i])
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (i+1!=nums[i]) 
                return vector<int>{nums[i], i+1};
        }
        return vector<int>();


        vector<int> res(2);
        for (int i=0; i<nums.size(); i++) {
            int p = abs(nums[i])-1;
            if (nums[p]>0) 
                nums[p] *= -1;
            else 
                res[0] = p+1;
        }
        for (int i=0; i<nums.size(); i++) 
            if (nums[i]>0) 
                res[1] = i+1;
        return res;
    }
};
// @lc code=end

