/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (37.09%)
 * Likes:    343
 * Dislikes: 640
 * Total Accepted:    100K
 * Total Submissions: 269.5K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * 
 * Note:
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B);
        int s2 = (G - E) * (H - F); 
        
        if (A>=G || C<=E || D<=F || B>=H)
            return s1 + s2; 
        return s1 - (min(G, C)-max(A, E))*(min(D, H)-max(B, F)) + s2;
    }
};
// @lc code=end

