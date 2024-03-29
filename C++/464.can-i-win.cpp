/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 *
 * https://leetcode.com/problems/can-i-win/description/
 *
 * algorithms
 * Medium (28.86%)
 * Likes:    1043
 * Dislikes: 177
 * Total Accepted:    54.2K
 * Total Submissions: 185.1K
 * Testcase Example:  '10\n11'
 *
 * In the "100 game" two players take turns adding, to a running total, any
 * integer from 1 to 10. The player who first causes the running total to reach
 * or exceed 100 wins.
 * 
 * What if we change the game so that players cannot re-use integers?
 * 
 * For example, two players might take turns drawing from a common pool of
 * numbers from 1 to 15 without replacement until they reach a total >= 100.
 * 
 * Given two integers maxChoosableInteger and desiredTotal, return true if the
 * first player to move can force a win, otherwise return false. Assume both
 * players play optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: maxChoosableInteger = 10, desiredTotal = 11
 * Output: false
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers
 * from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >=
 * desiredTotal.
 * Same with other integers chosen by the first player, the second player will
 * always win.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: maxChoosableInteger = 10, desiredTotal = 0
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: maxChoosableInteger = 10, desiredTotal = 1
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= maxChoosableInteger <= 20
 * 0 <= desiredTotal <= 300
 * 
 * 
 */
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canIWin(int num, int target) {
        // 可以从题目看到maxChoosableInteger最大不超过20，这就暗示我们可以使用状态压缩表示每个数字是否被用过了，当maxChoosableInteger

        if (num >= target) return true;
        if (num*(num+1)/2 < target) return false;
        
        unordered_map<int, bool> hash_map;
        return DFS(num, target, 0, hash_map);
    }
    
    bool DFS(int num, int target, int state, unordered_map<int, bool>& hash_map) {
        if (hash_map.count(state)) return hash_map[state];
        
        for (int i=0; i<num; ++i) {
            int cur = (1<<i);
            if ((cur&state) == 0) {
                if (target<=i+1 || !DFS(num, target-(i+1), cur|state, hash_map)) {
                    hash_map[state] = true;
                    return true;
                }
            }
        }
        hash_map[state] = false;
        return false;
    }
};
// @lc code=end

