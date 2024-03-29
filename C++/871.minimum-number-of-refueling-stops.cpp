/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 *
 * https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
 *
 * algorithms
 * Hard (35.97%)
 * Likes:    2727
 * Dislikes: 52
 * Total Accepted:    76.6K
 * Total Submissions: 211.9K
 * Testcase Example:  '1\n1\n[]'
 *
 * A car travels from a starting position to a destination which is target
 * miles east of the starting position.
 * 
 * There are gas stations along the way. The gas stations are represented as an
 * array stations where stations[i] = [positioni, fueli] indicates that the
 * i^th gas station is positioni miles east of the starting position and has
 * fueli liters of gas.
 * 
 * The car starts with an infinite tank of gas, which initially has startFuel
 * liters of fuel in it. It uses one liter of gas per one mile that it drives.
 * When the car reaches a gas station, it may stop and refuel, transferring all
 * the gas from the station into the car.
 * 
 * Return the minimum number of refueling stops the car must make in order to
 * reach its destination. If it cannot reach the destination, return -1.
 * 
 * Note that if the car reaches a gas station with 0 fuel left, the car can
 * still refuel there. If the car reaches the destination with 0 fuel left, it
 * is still considered to have arrived.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: target = 1, startFuel = 1, stations = []
 * Output: 0
 * Explanation: We can reach the target without refueling.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: target = 100, startFuel = 1, stations = [[10,100]]
 * Output: -1
 * Explanation: We can not reach the target (or even the first gas station).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: target = 100, startFuel = 10, stations =
 * [[10,60],[20,30],[30,30],[60,40]]
 * Output: 2
 * Explanation: We start with 10 liters of fuel.
 * We drive to position 10, expending 10 liters of fuel.  We refuel from 0
 * liters to 60 liters of gas.
 * Then, we drive from position 10 to position 60 (expending 50 liters of
 * fuel),
 * and refuel from 10 liters to 50 liters of gas.  We then drive to and reach
 * the target.
 * We made 2 refueling stops along the way, so we return 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= target, startFuel <= 10^9
 * 0 <= stations.length <= 500
 * 0 <= positioni <= positioni+1 < target
 * 1 <= fueli < 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n+1, startFuel);
        
        for (int k=0; k<n; ++k) {
            for (int i=k; i>=0 && dp[i]>=stations[k][0]; --i) {
                dp[i+1] = max(dp[i+1], dp[i]+stations[k][1]);
            }
        }
        
        for (int i=0; i<=n; ++i) {
            if (dp[i] >= target) return i;
        }
        return -1;

        priority_queue<int> pq;
        int fuel = startFuel, ans = 0;
        
        for (vector<int>& stop: stations) {
            if (fuel >= target) break;
            while (!pq.empty() && fuel< stop[0]) {
                fuel += pq.top();
                pq.pop();
                ans += 1;
            }
            if (fuel < stop[0]) return -1;
            pq.push(stop[1]);
        }
        while (!pq.empty() && fuel<target) {
            fuel += pq.top();
            pq.pop();
            ans += 1;
        }
        
        return fuel>=target ? ans : -1;

        priority_queue<int> pq;
        int fuel = startFuel, ans = 0;
        
        int i = 0, n = stations.size();
        while (fuel < target) {
            while (i<n && fuel>=stations[i][0]) pq.push(stations[i++][1]);
            
            if (pq.empty()) return -1;
            fuel += pq.top(); pq.pop();
            ans += 1;
        }
        return ans;
    }
};
// @lc code=end

