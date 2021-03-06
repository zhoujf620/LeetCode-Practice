/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (45.45%)
 * Likes:    937
 * Dislikes: 63
 * Total Accepted:    51.2K
 * Total Submissions: 112.6K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string s that consists of only uppercase English letters, you can
 * perform at most k operations on that string.
 * 
 * In one operation, you can choose any character of the string and change it
 * to any other uppercase English character.
 * 
 * Find the length of the longest sub-string containing all repeating letters
 * you can get after performing the above operations.
 * 
 * Note:
 * Both the string's length and k will not exceed 10^4.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "ABAB", k = 2
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "AABABBA", k = 1
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
       int ans = 0;
        
        vector<int> hash(26, 0);
        int left=0, right=0;
        for ( ; right<s.size(); right++) {
            hash[s[right]-'A'] ++;
            
            while (right-left+1 - *max_element(hash.begin(), hash.end()) > k) {
                ans = max(ans, right-left);
                
                hash[s[left]-'A'] --;
                left ++;
            }
        }
        return max(ans, right-left);


        int ans = 0;
        
        vector<int> hash(26, 0);
        int left=0, right=0;
        for (int max_cnt=0; right<s.size(); right++) {
            hash[s[right]-'A'] ++;
            // 保存的是当前遍历过的全局的最大值，它肯定是比实际的最大值大的
            max_cnt = max(max_cnt, hash[s[right]-'A']);
            
            while (right-left+1 - max_cnt > k) {   
                hash[s[left]-'A'] --;
                left ++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
// @lc code=end

