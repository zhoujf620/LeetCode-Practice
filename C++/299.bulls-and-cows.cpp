/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 *
 * https://leetcode.com/problems/bulls-and-cows/description/
 *
 * algorithms
 * Easy (40.96%)
 * Likes:    455
 * Dislikes: 505
 * Total Accepted:    121K
 * Total Submissions: 295.4K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * You are playing the following Bulls and Cows game with your friend: You
 * write down a number and ask your friend to guess what the number is. Each
 * time your friend makes a guess, you provide a hint that indicates how many
 * digits in said guess match your secret number exactly in both digit and
 * position (called "bulls") and how many digits match the secret number but
 * locate in the wrong position (called "cows"). Your friend will use
 * successive guesses and hints to eventually derive the secret number.
 * 
 * Write a function to return a hint according to the secret number and
 * friend's guess, use A to indicate the bulls and B to indicate the cows. 
 * 
 * Please note that both secret number and friend's guess may contain duplicate
 * digits.
 * 
 * Example 1:
 * 
 * 
 * Input: secret = "1807", guess = "7810"
 * 
 * Output: "1A3B"
 * 
 * Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
 * 
 * Example 2:
 * 
 * 
 * Input: secret = "1123", guess = "0111"
 * 
 * Output: "1A1B"
 * 
 * Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a
 * cow.
 * 
 * Note: You may assume that the secret number and your friend's guess only
 * contain digits, and their lengths are always equal.
 */
#include<vector>
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> s_count(10, 0), g_count(10, 0);
        int size = secret.size();
        int bull=0, cow=0;

        for (int i=0; i<size; i++) {
            s_count[secret[i]-'0']++;
            g_count[guess[i]-'0']++;
            
            if(secret[i]==guess[i])
                bull++;
        }
        for (int i=0; i<10; i++)
            cow += min(s_count[i], g_count[i]);
        cow -= bull;
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
// @lc code=end

int main() {
    string secret = "1807", guess = "7810";
    // string secret = "1123", guess = "0111";
    Solution sol;
    cout << sol.getHint(secret, guess) << endl;
}