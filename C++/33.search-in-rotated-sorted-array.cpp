/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while (left<right) {
            int mid = left + (right-left)/2;
            if (nums[mid]>nums.back())
                left = mid+1;
            else 
                right = mid;
        }

        int idx = left;
        
        // left=0, right=nums.size()-1;
        // while (left <= right) {
        //     int mid = left + (right-left)/2;
        //     int mid_rotated = (mid+idx) % nums.size();

        //     if (nums[mid_rotated] == target) 
        //         return mid_rotated;
        //     else if (nums[mid_rotated]<target)
        //         left = mid+1;
        //     else 
        //         right = mid-1;
        // }
        if (idx==0)
            left = 0, right = nums.size()-1;
        else if (target >= nums[0]) 
            left = 0, right = idx - 1;
        else 
            left = idx, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right--;
            else left ++;
        }
        return -1;
    }
};
// @lc code=end

