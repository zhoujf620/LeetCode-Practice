#
# @lc app=leetcode id=778 lang=python3
#
# [778] Swim in Rising Water
#
# https://leetcode.com/problems/swim-in-rising-water/description/
#
# algorithms
# Hard (61.18%)
# Likes:    3710
# Dislikes: 248
# Total Accepted:    173.3K
# Total Submissions: 282.7K
# Testcase Example:  '[[0,2],[1,3]]'
#
# You are given an n x n integer matrix grid where each value grid[i][j]
# represents the elevation at that point (i, j).
# 
# The rain starts to fall. At time t, the depth of the water everywhere is t.
# You can swim from a square to another 4-directionally adjacent square if and
# only if the elevation of both squares individually are at most t. You can
# swim infinite distances in zero time. Of course, you must stay within the
# boundaries of the grid during your swim.
# 
# Return the least time until you can reach the bottom right square (n - 1, n -
# 1) if you start at the top left square (0, 0).
# 
# 
# Example 1:
# 
# 
# Input: grid = [[0,2],[1,3]]
# Output: 3
# Explanation:
# At time 0, you are in grid location (0, 0).
# You cannot go anywhere else because 4-directionally adjacent neighbors have a
# higher elevation than t = 0.
# You cannot reach point (1, 1) until time 3.
# When the depth of water is 3, we can swim anywhere inside the grid.
# 
# 
# Example 2:
# 
# 
# Input: grid =
# [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
# Output: 16
# Explanation: The final route is shown.
# We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
# 
# 
# 
# Constraints:
# 
# 
# n == grid.length
# n == grid[i].length
# 1 <= n <= 50
# 0 <= grid[i][j] < n^2
# Each value grid[i][j] is unique.
# 
# 
#

# @lc code=start
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        pq = [(grid[0][0], 0, 0)]
        visited = set((0, 0))

        ans = 0
        while pq:
            t, i, j = heapq.heappop(pq)
            ans = max(ans, t)

            if i == j == len(grid) - 1:
                return ans
            
            for d in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                x, y = i + d[0], j + d[1]
                if x < 0 or x >= len(grid) or y < 0 or y >= len(grid) or (x, y) in visited:
                    continue
                heapq.heappush(pq, (grid[x][y], x, y))
                visited.add((x, y))

        return -1

        
# @lc code=end

