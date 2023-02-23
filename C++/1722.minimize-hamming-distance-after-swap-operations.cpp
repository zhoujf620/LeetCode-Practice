/*
 * @lc app=leetcode id=1722 lang=cpp
 *
 * [1722] Minimize Hamming Distance After Swap Operations
 *
 * https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/
 *
 * algorithms
 * Medium (48.73%)
 * Likes:    711
 * Dislikes: 22
 * Total Accepted:    14.8K
 * Total Submissions: 30.3K
 * Testcase Example:  '[1,2,3,4]\n[2,1,4,5]\n[[0,1],[2,3]]'
 *
 * You are given two integer arrays, source and target, both of length n. You
 * are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi]
 * indicates that you are allowed to swap the elements at index ai and index bi
 * (0-indexed) of array source. Note that you can swap elements at a specific
 * pair of indices multiple times and in any order.
 * 
 * The Hamming distance of two arrays of the same length, source and target, is
 * the number of positions where the elements are different. Formally, it is
 * the number of indices i for 0 <= i <= n-1 where source[i] != target[i]
 * (0-indexed).
 * 
 * Return the minimum Hamming distance of source and target after performing
 * any amount of swap operations on array source.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
 * Output: 1
 * Explanation: source can be transformed the following way:
 * - Swap indices 0 and 1: source = [2,1,3,4]
 * - Swap indices 2 and 3: source = [2,1,4,3]
 * The Hamming distance of source and target is 1 as they differ in 1 position:
 * index 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
 * Output: 2
 * Explanation: There are no allowed swaps.
 * The Hamming distance of source and target is 2 as they differ in 2
 * positions: index 1 and index 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps =
 * [[0,4],[4,2],[1,3],[1,4]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == source.length == target.length
 * 1 <= n <= 10^5
 * 1 <= source[i], target[i] <= 10^5
 * 0 <= allowedSwaps.length <= 10^5
 * allowedSwaps[i].length == 2
 * 0 <= ai, bi <= n - 1
 * ai != bi
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> root(n);
        for (int i=0; i<n; ++i) root[i] = i;

        for (auto& p: allowedSwaps) {
            int r1 = findRoot(p[0], root);
            int r2 = findRoot(p[1], root);
            if (r1 != r2) root[r1] = r2;
        }

        unordered_map<int, multiset<int>> root2SrcVal;
        for (int i=0; i<n; ++i) {
            root2SrcVal[findRoot(i, root)].insert(source[i]);
        }

        int ans = 0;
        for (int i=0; i<n; ++i) {
            int r = findRoot(i, root);
            if (!root2SrcVal[r].count(target[i])) ans += 1;
            else root2SrcVal[r].erase(root2SrcVal[r].find(target[i]));
        }
        return ans;
    }

    int findRoot(int i, vector<int>& root) {
        while (i != root[i]) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }

};
// @lc code=end
