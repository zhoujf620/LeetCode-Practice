/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 *
 * https://leetcode.com/problems/jump-game-iv/description/
 *
 * algorithms
 * Hard (43.82%)
 * Likes:    2260
 * Dislikes: 88
 * Total Accepted:    84.9K
 * Total Submissions: 193.4K
 * Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
 *
 * Given an array of integers arr, you are initially positioned at the first
 * index of the array.
 * 
 * In one step you can jump from index i to index:
 * 
 * 
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 * 
 * 
 * Return the minimum number of steps to reach the last index of the array.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
 * index 9 is the last index of the array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You do not need to jump.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last
 * index of the array.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * -10^8 <= arr[i] <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> hmap;
        for (int i=0; i<n; ++i) hmap[nums[i]].push_back(i);

        int ans = 0;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int q_size = q.size();
                while (q_size --) {
                int idx = q.front();
                q.pop();

                if (idx == n-1) return ans;
                if (idx-1 >= 0 && !visited[idx-1]) {
                    q.push(idx-1);
                    visited[idx-1] = true;
                }
                if (idx+1 < n && !visited[idx+1]) {
                    q.push(idx+1);
                    visited[idx+1] = true;
                }
                for (int nei: hmap[nums[idx]]) {
                    if (!visited[nei]) {
                        q.push(nei);
                        visited[nei];
                    }
                }
                hmap[nums[idx]] = vector<int>{};

            }
            ans += 1;
        }
        return -1;
    }
};
// @lc code=end

