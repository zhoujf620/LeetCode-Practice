/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (56.63%)
 * Likes:    1451
 * Dislikes: 115
 * Total Accepted:    130.5K
 * Total Submissions: 230.3K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // int findCircleNum(vector<vector<int>>& matrix) {
    //     int ans = 0;
    //     if(matrix.empty()) return ans;
        
    //     int n = matrix.size();
    //     vector<bool> visited(n, false);
        
    //     for (int i=0; i<n; i++) {
    //         if (!visited[i]) {
    //             DFS(matrix, visited, i);
    //             ans ++;
    //         }
    //     }
    //     return ans;
    // }
    
    // void DFS(vector<vector<int>>& matrix, vector<bool>& visited, int i) {
    //     visited[i] = true;
        
    //     for (int j=0; j<matrix.size(); j++) {
    //         if(matrix[i][j] && !visited[j])
    //             DFS(matrix, visited, j);
    //     }
    // }
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size(), ans = n;
        
        // vector<int> root(n, -1);
        for (int i=0; i<n; ++i) root[i] = i;
        
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (nums[i][j] == 1) {
                    int p1 = findRoot(root, i);
                    int p2 = findRoot(root, j);
                    if (p1 != p2) {
                        ans --;
                        root[p2] = p1;
                    }
                }
            }
        }
        return ans;
    }
    
    int findRoot(vector<int>& root, int i) {
        // while (-1 != root[i]) {
        while (i != root[i]) {
            root[i] = root[root[i]]; // 路径压缩
            i = root[i];
        }
        return i;
    }
};
// @lc code=end

