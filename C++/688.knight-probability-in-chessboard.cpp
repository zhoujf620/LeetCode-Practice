/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (51.60%)
 * Likes:    2134
 * Dislikes: 303
 * Total Accepted:    84.6K
 * Total Submissions: 163.3K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * On an n x n chessboard, a knight starts at the cell (row, column) and
 * attempts to make exactly k moves. The rows and columns are 0-indexed, so the
 * top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
 * 
 * A chess knight has eight possible moves it can make, as illustrated below.
 * Each move is two cells in a cardinal direction, then one cell in an
 * orthogonal direction.
 * 
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 * 
 * The knight continues moving until it has made exactly k moves or has moved
 * off the chessboard.
 * 
 * Return the probability that the knight remains on the board after it has
 * stopped moving.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 2, row = 0, column = 0
 * Output: 0.06250
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 0, row = 0, column = 0
 * Output: 1.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 25
 * 0 <= k <= 100
 * 0 <= row, column <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double knightProbability(int n, int moves, int row, int col) {
        vector<vector<int>> dirs{{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        
        vector<vector<double>> dp(n, vector<double>(n, 1));
        for (int k=1; k<=moves; ++k) {
            vector<vector<double>> tmp(n, vector<double>(n, 0));
                
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    
                    for (auto d: dirs) {
                        int x = i + d[0], y = j + d[1];
                        if (x<0 || x>=n || y<0 || y>=n) continue;
                        tmp[i][j] += dp[x][y];
                    }
                }
            }
            dp = tmp;
        }
        return dp[row][col] / pow(8, moves);
    }
};
// @lc code=end

