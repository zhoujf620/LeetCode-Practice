/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include<string>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        long ans = 0, sign = 1;

        int i = 0;
        for (; i<str.size() && str[i]==' '; i++) {};
        if (i==str.size()) return ans;
        
        if(str[i]=='-' || str[i]=='+')
            sign = (str[i++]=='-') ? -1 : 1;
        
        for (; i<str.size() && isdigit(str[i]); ++i) {
            ans = ans * 10 + (str[i]-'0');
            if (ans*sign >= INT_MAX) return INT_MAX;
            if (ans*sign <= INT_MIN) return INT_MIN;
        }
        return ans*sign;    
    }
};
// @lc code=end

int main() {
    Solution sol;
    // string str = "                 ";
    // string str="2147483648";
    string str="   -42";
    int ans = sol.myAtoi(str);
    cout<<ans<<endl;
}