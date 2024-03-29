/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (27.08%)
 * Likes:    770
 * Dislikes: 244
 * Total Accepted:    40.3K
 * Total Submissions: 148.4K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two. The
 * relative order of the digits from the same array must be preserved. Return
 * an array of the k digits.
 * 
 * Note: You should try to optimize your time and space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * Output:
 * [9, 8, 6, 5, 3]
 * 
 * Example 2:
 * 
 * 
 * Input:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * Output:
 * [6, 7, 6, 0, 4]
 * 
 * Example 3:
 * 
 * 
 * Input:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * Output:
 * [9, 8, 9]
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        for (int i=max(0, k-n2); i<=min(k, n1); ++i) {
            res = max(res, mergeVector(maxVector(nums1, i), 
                                       maxVector(nums2, k-i)));
        }
        return res;
    }
    vector<int> maxVector(vector<int>& nums, int k) {
        int drop = nums.size() - k;
        vector<int> stack;
        for (int num : nums) {
            while (drop>0 && !stack.empty() && stack.back() < num) {
                stack.pop_back();
                --drop;
            }
            stack.push_back(num);
        }
        stack.resize(k);
        return stack;
    }
    vector<int> mergeVector(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        while (!nums1.empty() ||! nums2.empty()) {
            if (nums1 > nums2) {
                res.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else {
                res.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        return res;
    }
};
// @lc code=end

