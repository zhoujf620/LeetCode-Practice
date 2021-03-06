/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> path;

        DFS(candidates, target, 0, path, res);
        return res;
    }

    void DFS(vector<int>& nums, int target, int index, vector<int>& path, vector<vector<int>>& res) {
        if(target<0) 
            return;
        else if (target==0)
            res.push_back(path);
        else {
            for(int i=index; i<nums.size(); i++) {
                // 防止重复！
                if (i==index || nums[i]!=nums[i-1]){
                    path.push_back(nums[i]);
                    DFS(nums, target-nums[i], i+1, path, res);
                    path.pop_back();
                }
            }
        }
    }
};
// @lc code=end

