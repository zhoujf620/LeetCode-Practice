#
# @lc app=leetcode id=79 lang=python
#
# [79] Word Search
#
# https://leetcode.com/problems/word-search/description/
#
# algorithms
# Medium (32.77%)
# Likes:    2403
# Dislikes: 127
# Total Accepted:    350.4K
# Total Submissions: 1.1M
# Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
#
# Given a 2D board and a word, find if the word exists in the grid.
# 
# The word can be constructed from letters of sequentially adjacent cell, where
# "adjacent" cells are those horizontally or vertically neighboring. The same
# letter cell may not be used more than once.
# 
# Example:
# 
# 
# board =
# [
# ⁠ ['A','B','C','E'],
# ⁠ ['S','F','C','S'],
# ⁠ ['A','D','E','E']
# ]
# 
# Given word = "ABCCED", return true.
# Given word = "SEE", return true.
# Given word = "ABCB", return false.
# 
# 
#

# @lc code=start
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board:
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(board, i, j, word): 
                    return True 
        return False
    
    def dfs(self, board, i, j, word):
        if len(word) == 0:
            return True 
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[0]:
            return False
        
        temp = board[i][j]
        board[i][j] = '#'
        res = (self.dfs(board, i+1, j, word[1:]) or 
              self.dfs(board, i-1, j, word[1:]) or
              self.dfs(board, i, j+1, word[1:]) or 
              self.dfs(board, i, j-1, word[1:]))
        board[i][j] = temp
        return res



# @lc code=end

sol = Solution()    
board = [["C","A","A"],["A","A","A"],["B","C","D"]]

word = "AAB"

sol.exist(board, word)