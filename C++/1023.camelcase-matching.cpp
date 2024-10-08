/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 *
 * https://leetcode.com/problems/camelcase-matching/description/
 *
 * algorithms
 * Medium (60.53%)
 * Likes:    752
 * Dislikes: 272
 * Total Accepted:    39.4K
 * Total Submissions: 64.8K
 * Testcase Example:  '["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]\n"FB"'
 *
 * Given an array of strings queries and a string pattern, return a boolean
 * array answer where answer[i] is true if queries[i] matches pattern, and
 * false otherwise.
 * 
 * A query word queries[i] matches pattern if you can insert lowercase English
 * letters pattern so that it equals the query. You may insert each character
 * at any position and you may not insert any characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FB"
 * Output: [true,false,true,true,false]
 * Explanation: "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
 * "FootBall" can be generated like this "F" + "oot" + "B" + "all".
 * "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FoBa"
 * Output: [true,false,true,false,false]
 * Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
 * "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FoBaT"
 * Output: [false,true,false,false,false]
 * Explanation: "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r"
 * + "T" + "est".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= pattern.length, queries.length <= 100
 * 1 <= queries[i].length <= 100
 * queries[i] and pattern consist of English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (string& q: queries) {
            ans.push_back(check(q, pattern));
        }
        return ans;
    }

    bool check(string& q, string& p) {
        int i = 0, j = 0;
        while (i<q.size() && j<p.size()) {
            if (q[i] == p[j]) i += 1, j += 1;
            else if (islower(q[i])) i += 1;
            else return false;
        }
        while (i<q.size()) {
            if (!islower(q[i])) return false;
            i += 1;
        }
        return j==p.size();
    }

};
// @lc code=end

