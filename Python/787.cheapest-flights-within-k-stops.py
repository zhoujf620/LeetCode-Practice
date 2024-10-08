#
# @lc app=leetcode id=787 lang=python
#
# [787] Cheapest Flights Within K Stops
#
# https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
#
# algorithms
# Medium (36.94%)
# Likes:    1140
# Dislikes: 41
# Total Accepted:    63K
# Total Submissions: 170.3K
# Testcase Example:  '3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n1'
#
# There are n cities connected by m flights. Each fight starts from city u and
# arrives at v with a price w.
# 
# Now given all the cities and flights, together with starting city src and the
# destination dst, your task is to find the cheapest price from src to dst with
# up to k stops. If there is no such route, output -1.
# 
# 
# Example 1:
# Input: 
# n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
# src = 0, dst = 2, k = 1
# Output: 200
# Explanation: 
# The graph looks like this:
# 
# 
# The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as
# marked red in the picture.
# 
# 
# Example 2:
# Input: 
# n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
# src = 0, dst = 2, k = 0
# Output: 500
# Explanation: 
# The graph looks like this:
# 
# 
# The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as
# marked blue in the picture.
# 
# Note:
# 
# 
# The number of nodes n will be in range [1, 100], with nodes labeled from 0 to
# n - 1.
# The size of flights will be in range [0, n * (n - 1) / 2].
# The format of each flight will be (src, dst, price).
# The price of each flight will be in the range [1, 10000].
# k is in the range of [0, n - 1].
# There will not be any duplicated flights or self cycles.
# 
# 
#

import collections
import heapq

# @lc code=start
class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type K: int
        :rtype: int
        """

        # Dijkstra
        adj = collections.defaultdict(list)
        for u, v, w in flights:
            adj[u].append((v, w))

        ans = float('inf')
        stop = 0
        queue = collections.deque([(src, 0)])
        while queue:
            # no for loop in Dijkstra with heap
            for _ in range(len(queue)):
                node, cost = queue.popleft()
                if node == dst:
                    ans = min(ans, cost)
                
                for nei, w in adj[node]:
                    if cost + w >= ans:
                        continue
                    queue.append((nei, cost + w))
            if stop > k:
                break
            stop += 1
        return ans if ans < float('inf') else -1
    
        # Dijkstra with heap
        adj = collections.defaultdict(list)
        for u, v, w in flights:
            adj[u].append((v, w))
        
        q = [(0, src, K+1)]
        while q:
            dist, node, stop = heapq.heappop(q)
            if node == dst:
                return dist 
            if stop>0:
                for v, w in adj[node]:
                    heapq.heappush(q, (dist+w, v, stop-1))
        return -1
    

        # Bellman-Ford
        dist = [float('inf')] * n
        dist[src] = 0
        for _ in range(K+1):
            tmp = dist[:]
            for u, v, w in flights:
                tmp[v] = min(tmp[v], dist[u] + w)
            dist = tmp
        return dist[dst] if dist[dst] < float('inf') else -1
    
    
# @lc code=end

