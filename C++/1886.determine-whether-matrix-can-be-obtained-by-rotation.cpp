/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 *
 * https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
 *
 * algorithms
 * Easy (55.43%)
 * Likes:    808
 * Dislikes: 72
 * Total Accepted:    39.1K
 * Total Submissions: 70.6K
 * Testcase Example:  '[[0,1],[1,0]]\n[[1,0],[0,1]]'
 *
 * Given two n x n binary matrices mat and target, return true if it is
 * possible to make mat equal to target by rotating mat in 90-degree
 * increments, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
 * Output: true
 * Explanation: We can rotate mat 90 degrees clockwise to make mat equal
 * target.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
 * Output: false
 * Explanation: It is impossible to make mat equal to target by rotating mat.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
 * Output: true
 * Explanation: We can rotate mat 90 degrees clockwise two times to make mat
 * equal target.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == mat.length == target.length
 * n == mat[i].length == target[i].length
 * 1 <= n <= 10
 * mat[i][j] and target[i][j] are either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> ans(4, true);
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(mat[i][j] != target[i][j]) ans[0]=false;
                if(mat[i][j] != target[n-j-1][i]) ans[1]=false;
                if(mat[i][j] != target[n-i-1][n-j-1]) ans[2]=false;
                if(mat[i][j] != target[j][n-i-1]) ans[3]=false;
            }
        }
        return ans[0] || ans[1] || ans[2] || ans[3];
    }
};
// @lc code=end

