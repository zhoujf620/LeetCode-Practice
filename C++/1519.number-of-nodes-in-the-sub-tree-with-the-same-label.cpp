/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 *
 * https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
 *
 * algorithms
 * Medium (40.74%)
 * Likes:    1826
 * Dislikes: 715
 * Total Accepted:    64.9K
 * Total Submissions: 117.8K
 * Testcase Example:  '7\n[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n"abaedcd"'
 *
 * You are given a tree (i.e. a connected, undirected graph that has no cycles)
 * consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. The
 * root of the tree is the node 0, and each node of the tree has a label which
 * is a lower-case character given in the string labels (i.e. The node with the
 * number i has the label labels[i]).
 * 
 * The edges array is given on the form edges[i] = [ai, bi], which means there
 * is an edge between nodes ai and bi in the tree.
 * 
 * Return an array of size n where ans[i] is the number of nodes in the subtree
 * of the i^th node which have the same label as node i.
 * 
 * A subtree of a tree T is the tree consisting of a node in T and all of its
 * descendant nodes.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels =
 * "abaedcd"
 * Output: [2,1,1,1,1,1,1]
 * Explanation: Node 0 has label 'a' and its sub-tree has node 2 with label 'a'
 * as well, thus the answer is 2. Notice that any node is part of its sub-tree.
 * Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 and 5, as
 * nodes 4 and 5 have different labels than node 1, the answer is just 1 (the
 * node itself).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
 * Output: [4,2,1,1]
 * Explanation: The sub-tree of node 2 contains only node 2, so the answer is
 * 1.
 * The sub-tree of node 3 contains only node 3, so the answer is 1.
 * The sub-tree of node 1 contains nodes 1 and 2, both have label 'b', thus the
 * answer is 2.
 * The sub-tree of node 0 contains nodes 0, 1, 2 and 3, all with label 'b',
 * thus the answer is 4.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
 * Output: [3,2,1,1,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * labels.length == n
 * labels is consisting of only of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        vector<int> ans(n, 0);
        
        visited[0] = true;
        DFS(0, ans, labels, graph, visited);
        return ans;
    }

    vector<int> DFS(int node, vector<int>& ans, string& labels, 
            vector<vector<int>>& graph, vector<bool>& visited) {
        
        vector<int> label_cnt(26, 0), tmp;
        for (int nei: graph[node]) {
            if (visited[nei]) continue;

            visited[nei] = true;
            tmp = DFS(nei, ans, labels, graph, visited);
            for (int i=0; i<26; ++i) label_cnt[i] += tmp[i];
        }
        label_cnt[labels[node] - 'a'] += 1;
        ans[node] = label_cnt[labels[node] - 'a'];
        return label_cnt;
    }
};
// @lc code=end

