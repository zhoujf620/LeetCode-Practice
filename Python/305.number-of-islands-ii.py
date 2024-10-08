#
# @lc app=leetcode id=305 lang=python3
#
# [305] Number of Islands II
#
# https://leetcode.com/problems/number-of-islands-ii/description/
#
# algorithms
# Hard (39.89%)
# Likes:    1866
# Dislikes: 72
# Total Accepted:    148.1K
# Total Submissions: 371.2K
# Testcase Example:  '3\n3\n[[0,0],[0,1],[1,2],[2,1]]'
#
# You are given an empty 2D binary grid grid of size m x n. The grid represents
# a map where 0's represent water and 1's represent land. Initially, all the
# cells of grid are water cells (i.e., all the cells are 0's).
# 
# We may perform an add land operation which turns the water at position into a
# land. You are given an array positions where positions[i] = [ri, ci] is the
# position (ri, ci) at which we should operate the i^th operation.
# 
# Return an array of integers answer where answer[i] is the number of islands
# after turning the cell (ri, ci) into a land.
# 
# An island is surrounded by water and is formed by connecting adjacent lands
# horizontally or vertically. You may assume all four edges of the grid are all
# surrounded by water.
# 
# 
# Example 1:
# 
# 
# Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
# Output: [1,1,2,3]
# Explanation:
# Initially, the 2d grid is filled with water.
# - Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. We
# have 1 island.
# - Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land. We
# still have 1 island.
# - Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land. We
# have 2 islands.
# - Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land. We
# have 3 islands.
# 
# 
# Example 2:
# 
# 
# Input: m = 1, n = 1, positions = [[0,0]]
# Output: [1]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= m, n, positions.length <= 10^4
# 1 <= m * n <= 10^4
# positions[i].length == 2
# 0 <= ri < m
# 0 <= ci < n
# 
# 
# 
# Follow up: Could you solve it in time complexity O(k log(mn)), where k ==
# positions.length?
# 
#

# @lc code=start
class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        cnt = 0
        ans = []
        roots = [-1] * (m * n)
        for i, j in positions:
            idx = i * n + j
            if roots[idx] != -1:
                ans.append(cnt)
                continue
            roots[idx] = idx
            cnt += 1
            for d in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                x, y = i + d[0], j + d[1]
                if x < 0 or x >= m or y < 0 or y >= n:
                    continue
                new_idx = x * n + y
                if roots[new_idx] == -1:
                    continue
                p1 = self.findRoot(roots, idx)
                p2 = self.findRoot(roots, new_idx)
                if p1 != p2:
                    roots[p1] = p2
                    cnt -= 1
            ans.append(cnt)
        return ans

    def findRoot(self, roots, i):
        while roots[i] != i:
            roots[i] = roots[roots[i]]
            i = roots[i]
        return i
        
# @lc code=end

