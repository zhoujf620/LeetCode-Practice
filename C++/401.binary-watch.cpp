/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (46.21%)
 * Likes:    464
 * Dislikes: 805
 * Total Accepted:    74.6K
 * Total Submissions: 161.1K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */
#include<vector>
#include<string>
#include<bitset>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        
        for (int h=0; h<12; ++h) {
            for (int m=0; m<60; ++m) {
                if (count_one(h)+count_one(m) == num) {
                // if (bitset<10>((h << 6) + m).count() == num) {
                    res.push_back(to_string(h) + 
                                  (m<10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
    
    int count_one(int num) {
        int cnt = 0;
        while (num) {
            cnt ++;
            num = num & (num-1);
        }
        return cnt;
    }
};
// @lc code=end

