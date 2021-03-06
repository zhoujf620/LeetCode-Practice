/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 *
 * https://leetcode.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (54.24%)
 * Likes:    642
 * Dislikes: 258
 * Total Accepted:    173.2K
 * Total Submissions: 319.3K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 
 * Given two strings s and t which consist of only lowercase letters.
 * 
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 * 
 * Find the letter that was added in t.
 * 
 * Example:
 * 
 * Input:
 * s = "abcd"
 * t = "abcde"
 * 
 * Output:
 * e
 * 
 * Explanation:
 * 'e' is the letter that was added.
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (char ch: s) ans ^= (ch-'a');
        for (char ch: t) ans ^= (ch-'a');
        return ans+'a';

        char ans = 0;
        for (char ch: s) ans ^= ch;
        for (char ch: t) ans ^= ch;
        return ans;
    }
};
// @lc code=end

