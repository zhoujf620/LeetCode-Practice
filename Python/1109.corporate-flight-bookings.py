#
# @lc app=leetcode id=1109 lang=python3
#
# [1109] Corporate Flight Bookings
#
# https://leetcode.com/problems/corporate-flight-bookings/description/
#
# algorithms
# Medium (61.73%)
# Likes:    1630
# Dislikes: 160
# Total Accepted:    65.4K
# Total Submissions: 105.3K
# Testcase Example:  '[[1,2,10],[2,3,20],[2,5,25]]\n5'
#
# There are n flights that are labeled from 1 to n.
# 
# You are given an array of flight bookings bookings, where bookings[i] =
# [firsti, lasti, seatsi] represents a booking for flights firsti through lasti
# (inclusive) with seatsi seats reserved for each flight in the range.
# 
# Return an array answer of length n, where answer[i] is the total number of
# seats reserved for flight i.
# 
# 
# Example 1:
# 
# 
# Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
# Output: [10,55,45,25,25]
# Explanation:
# Flight labels:        1   2   3   4   5
# Booking 1 reserved:  10  10
# Booking 2 reserved:      20  20
# Booking 3 reserved:      25  25  25  25
# Total seats:         10  55  45  25  25
# Hence, answer = [10,55,45,25,25]
# 
# 
# Example 2:
# 
# 
# Input: bookings = [[1,2,10],[2,2,15]], n = 2
# Output: [10,25]
# Explanation:
# Flight labels:        1   2
# Booking 1 reserved:  10  10
# Booking 2 reserved:      15
# Total seats:         10  25
# Hence, answer = [10,25]
# 
# 
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 2 * 10^4
# 1 <= bookings.length <= 2 * 10^4
# bookings[i].length == 3
# 1 <= firsti <= lasti <= n
# 1 <= seatsi <= 10^4
# 
# 
#

# @lc code=start
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        events = [0] * (n+1)
        for b in bookings:
            events[b[0]-1] += b[2]
            events[b[1]] -= b[2]
        
        for i in range(1, n):
            events[i] += events[i-1]
        return events[:-1]
# @lc code=end

