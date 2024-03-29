/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 *
 * https://leetcode.com/problems/jump-game-iii/description/
 *
 * algorithms
 * Medium (61.20%)
 * Likes:    188
 * Dislikes: 4
 * Total Accepted:    12.8K
 * Total Submissions: 21K
 * Testcase Example:  '[4,2,3,0,3,1,2]\n5'
 *
 * Given an array of non-negative integers arr, you are initially positioned at
 * start index of the array. When you are at index i, you can jump to i +
 * arr[i] or i - arr[i], check if you can reach to any index with value 0.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,2,3,0,3,1,2], start = 5
 * Output: true
 * Explanation: 
 * All possible ways to reach at index 3 with value 0 are: 
 * index 5 -> index 4 -> index 1 -> index 3 
 * index 5 -> index 6 -> index 4 -> index 1 -> index 3 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [4,2,3,0,3,1,2], start = 0
 * Output: true 
 * Explanation: 
 * One possible way to reach at index 3 with value 0 is: 
 * index 0 -> index 4 -> index 1 -> index 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [3,0,2,1,2], start = 2
 * Output: false
 * Explanation: There is no way to reach at index 1 with value 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * 0 <= arr[i] < arr.length
 * 0 <= start < arr.length
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = nums.size();
        
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            
            int idx = q.front();
            q.pop();
            
            if (nums[idx] == 0) return true;
            if (visited.count(idx)) continue;
            
            visited.insert(idx);
            if (idx+nums[idx]<n ) q.push(idx+nums[idx]);
            if (idx-nums[idx]>=0) q.push(idx-nums[idx]);
        }
        return false;
        
        // int n = arr.size();
        // while (true) {
        //     int flag = 0;
        //     for (int i=0; i<n; i++) {
        //         if (arr[i]==0)
        //             continue;
        //         if ((i+arr[i]<n && arr[i+arr[i]]==0) || (i-arr[i]>=0 && arr[i-arr[i]]==0)) {
        //             arr[i] = 0;
        //             flag = 1;
        //         }
        //     }
        //     if (arr[start]==0)
        //         return true;
        //     if (flag==0)
        //         break;
        // }
        
        // return false;
    }

    // unordered_set<int> visited;

    // bool canReach(vector<int>& arr, int start) {
    //     if (start>=0 && start<arr.size() && !visited.count(start)) {
    //         visited.insert(start);
    //         return arr[start]==0 || canReach(arr, start+arr[start]) || canReach(arr, start-arr[start]);
    //     }
    //     return false;
    // }
};
// @lc code=end

