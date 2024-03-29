/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (49.24%)
 * Likes:    3865
 * Dislikes: 174
 * Total Accepted:    707.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min=INT_MAX;
        int ans = 0;
        for (int p: prices) {
            cur_min = min(cur_min, p);
            ans = max(ans, p-cur_min);
        }
        return ans; 

        // subarray maximum sum
        int cur_max=0, ans=0;
        for(int i=1; i<prices.size(); i++) {
            int profit = prices[i]-prices[i-1];
            cur_max = max(cur_max+profit, profit);
            ans = max(cur_max, ans);
        }
        return ans;
 

        int buy=INT_MIN, sell=INT_MIN;
        for (int p: prices) {
            buy = max(buy, -p);
            sell = max(sell, buy+p);
        }
        return max(0, sell);


        int n = prices.size();
        if (n<=1) return 0;

        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        buy[0] = -prices[0];  
        for (int i=1; i<n; i++) {
            buy[i] = max(buy[i-1], -prices[i]);
            sell[i] = max(sell[i-1], buy[i]+prices[i]);
        }
        return sell.back();
    }
};
// @lc code=end

