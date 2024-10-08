#
# @lc app=leetcode id=815 lang=python3
#
# [815] Bus Routes
#
# https://leetcode.com/problems/bus-routes/description/
#
# algorithms
# Hard (47.62%)
# Likes:    4256
# Dislikes: 123
# Total Accepted:    208.3K
# Total Submissions: 437.3K
# Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
#
# You are given an array routes representing bus routes where routes[i] is a
# bus route that the i^th bus repeats forever.
# 
# 
# For example, if routes[0] = [1, 5, 7], this means that the 0^th bus travels
# in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
# 
# 
# You will start at the bus stop source (You are not on any bus initially), and
# you want to go to the bus stop target. You can travel between bus stops by
# buses only.
# 
# Return the least number of buses you must take to travel from source to
# target. Return -1 if it is not possible.
# 
# 
# Example 1:
# 
# 
# Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
# Output: 2
# Explanation: The best strategy is take the first bus to the bus stop 7, then
# take the second bus to the bus stop 6.
# 
# 
# Example 2:
# 
# 
# Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target
# = 12
# Output: -1
# 
# 
# 
# 
# 
# Constraints:
# 
# 
# 1 <= routes.length <= 500.
# 1 <= routes[i].length <= 10^5
# All the values of routes[i] are unique.
# sum(routes[i].length) <= 10^5
# 0 <= routes[i][j] < 10^6
# 0 <= source, target < 10^6
# 
# 
#

# @lc code=start
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0

        stop2busIdx = collections.defaultdict(set)
        for i, route in enumerate(routes):
            for stop in route:
                stop2busIdx[stop].add(i)


        queue = collections.deque([source])
        visited_stop = set([source])
        visited_bus = set()
        
        ans = 0
        while queue:
            ans += 1
            for _ in range(len(queue)):
                stop = queue.popleft()

                for busIdx in stop2busIdx[stop]:
                    if busIdx in visited_bus:
                        continue
                    visited_bus.add(busIdx)

                    for next_stop in routes[busIdx]:
                        if next_stop in visited_stop:
                            continue
                        if next_stop == target:
                            return ans
                        
                        visited_stop.add(next_stop)
                        queue.append(next_stop)
        return -1
        
# @lc code=end

