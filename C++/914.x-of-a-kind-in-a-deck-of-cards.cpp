/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 *
 * https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
 *
 * algorithms
 * Easy (34.03%)
 * Likes:    358
 * Dislikes: 90
 * Total Accepted:    29.7K
 * Total Submissions: 87.2K
 * Testcase Example:  '[1,2,3,4,4,3,2,1]'
 *
 * In a deck of cards, each card has an integer written on it.
 * 
 * Return true if and only if you can choose X >= 2 such that it is possible to
 * split the entire deck into 1 or more groups of cards, where:
 * 
 * 
 * Each group has exactly X cards.
 * All the cards in each group have the same integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: deck = [1,2,3,4,4,3,2,1]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: deck = [1,1,1,2,2,2,3,3]
 * Output: false´
 * Explanation: No possible partition.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: deck = [1]
 * Output: false
 * Explanation: No possible partition.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: deck = [1,1]
 * Output: true
 * Explanation: Possible partition [1,1].
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: deck = [1,1,2,2,2,2]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[2,2].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= deck.length <= 10^4
 * 0 <= deck[i] < 10^4
 * 
 * 
 */
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& nums) {
        if (nums.size()<=1) 
            return false;
        
        unordered_map<int, int> cnts;
        for (int num: nums) cnts[num]++;
        
        int gcd = cnts.begin()->second;
        for (auto it: cnts) gcd = __gcd(it.second, gcd);
        return gcd > 1;
        
//         int min_cnt = INT_MAX;
//         for (auto it=cnts.begin(); it!=cnts.end(); it++)
//             min_cnt = min(min_cnt, it->second);
        
//         for (auto it=cnts.begin(); it!=cnts.end(); it++)
//             if (it->second%min_cnt != 0)
//                 return false;
//         return true;
    }
};
// @lc code=end

