/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (58.87%)
 * Likes:    2743
 * Dislikes: 89
 * Total Accepted:    476.5K
 * Total Submissions: 808.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#include<vector>
#include<iostream>
using namespace std; 

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        
        DFS(nums, res, path, visited);
        return res;
    }

    void DFS(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& visited) {
        if (path.size()==nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (!visited[i]) {
                path.push_back(nums[i]);
                visited[i] = true;
                DFS(nums, res, path, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     DFS(nums, 0, res);
    //     return res;
    // }
    // // DFS 产生一个全排列，idx=0 这个位置遍历一边
    // void DFS(vector<int>& nums, int pos, vector<vector<int>>& res) {
    //     if (pos==nums.size()) {
    //         res.push_back(nums);
    //         return;
    //     } 
    //     for (int i=pos; i<nums.size(); i++) {
    //         swap(nums[i], nums[pos]);
    //         DFS(nums, pos+1, res);
    //         // 如果nums传地址
    //         swap(nums[i], nums[pos]);
    //     }
    // }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            res.push_back(nums);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums{1,2,3};
    vector<vector<int>> res = sol.permute(nums);
}