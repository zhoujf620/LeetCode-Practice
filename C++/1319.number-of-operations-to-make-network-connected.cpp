/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 *
 * https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
 *
 * algorithms
 * Medium (53.47%)
 * Likes:    476
 * Dislikes: 7
 * Total Accepted:    19.9K
 * Total Submissions: 37.1K
 * Testcase Example:  '4\n[[0,1],[0,2],[1,2]]'
 *
 * There are n computers numbered from 0 to n-1 connected by ethernet cables
 * connections forming a network where connections[i] = [a, b] represents a
 * connection between computers a and b. Any computer can reach any other
 * computer directly or indirectly through the network.
 * 
 * Given an initial computer network connections. You can extract certain
 * cables between two directly connected computers, and place them between any
 * pair of disconnected computers to make them directly connected. Return the
 * minimum number of times you need to do this in order to make all the
 * computers connected. If it's not possible, return -1. 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, connections = [[0,1],[0,2],[1,2]]
 * Output: 1
 * Explanation: Remove cable between computer 1 and 2 and place between
 * computers 1 and 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
 * Output: -1
 * Explanation: There are not enough cables.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 1 <= connections.length <= min(n*(n-1)/2, 10^5)
 * connections[i].length == 2
 * 0 <= connections[i][0], connections[i][1] < n
 * connections[i][0] != connections[i][1]
 * There are no repeated connections.
 * No two computers are connected by more than one cable.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> root(n);
        for (int i=0; i<n; ++i) root[i] = i;
        
        int extra = 0;
        for (vector<int>& edge: connections) {
            int p1 = findRoot(root, edge[0]);
            int p2 = findRoot(root, edge[1]);
            if (p1 != p2) root[p1] = p2;
            else extra += 1;
        }
        
        int group = 0;
        for (int i=0; i<n; ++i) if (root[i] == i) group += 1;
        
        if (extra >= group-1) return group - 1;
        else return -1;
    }
    
    int findRoot(vector<int>& root, int i) {
        while (root[i] != i) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }
};
// @lc code=end

