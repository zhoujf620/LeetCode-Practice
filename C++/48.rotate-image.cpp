/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<i; j++) {
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }
        // for (int i=0; i<n; i++)
        //     reverse(matrix[i].begin(), matrix[i].end());

        int n = matrix.size(), temp;
        for (int i=0; i<n/2; i++) {
            for (int j=i; j<n-i-1; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
};
// @lc code=end
