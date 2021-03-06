/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 *
 * https://leetcode.com/problems/robot-return-to-origin/description/
 *
 * algorithms
 * Easy (72.78%)
 * Likes:    836
 * Dislikes: 614
 * Total Accepted:    210.3K
 * Total Submissions: 288.9K
 * Testcase Example:  '"UD"'
 *
 * There is a robot starting at position (0, 0), the origin, on a 2D plane.
 * Given a sequence of its moves, judge if this robot ends up at (0, 0) after
 * it completes its moves.
 * 
 * The move sequence is represented by a string, and the character moves[i]
 * represents its ith move. Valid moves are R (right), L (left), U (up), and D
 * (down). If the robot returns to the origin after it finishes all of its
 * moves, return true. Otherwise, return false.
 * 
 * Note: The way that the robot is "facing" is irrelevant. "R" will always make
 * the robot move to the right once, "L" will always make it move left, etc.
 * Also, assume that the magnitude of the robot's movement is the same for each
 * move.
 * 
 * Example 1:
 * 
 * 
 * Input: "UD"
 * Output: true 
 * Explanation: The robot moves up once, and then down once. All moves have the
 * same magnitude, so it ended up at the origin where it started. Therefore, we
 * return true.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "LL"
 * Output: false
 * Explanation: The robot moves left twice. It ends up two "moves" to the left
 * of the origin. We return false because it is not at the origin at the end of
 * its moves.
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> directs(2, 0);
        for (char ch: moves) {
            if (ch=='U') directs[0]++;
            else if (ch=='D') directs[0]--;
            else if (ch=='R') directs[1]++;
            else if (ch=='L') directs[1]--;
        }
        return directs[0]==0 && directs[1]==0;
    }
};
// @lc code=end

