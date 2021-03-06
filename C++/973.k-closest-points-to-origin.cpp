/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 *
 * https://leetcode.com/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (61.62%)
 * Likes:    1037
 * Dislikes: 87
 * Total Accepted:    174.8K
 * Total Submissions: 283.7K
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * We have a list of points on the plane.  Find the K closest points to the
 * origin (0, 0).
 * 
 * (Here, the distance between two points on a plane is the Euclidean
 * distance.)
 * 
 * You may return the answer in any order.  The answer is guaranteed to be
 * unique (except for the order that it is in.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[1,3],[-2,2]], K = 1
 * Output: [[-2,2]]
 * Explanation: 
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest K = 1 points from the origin, so the answer is just
 * [[-2,2]].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 * Output: [[3,3],[-2,4]]
 * (The answer [[-2,4],[3,3]] would also be accepted.)
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 * 
 * 
 * 
 */
#include<vector>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, int>> dists;
        for (int i=0; i<points.size(); ++i) {
            int dist = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            dists.push_back(make_pair(dist, i));
        }

        sort(dists.begin(), dists.end());

        // return vector<vector<int>>(dists.begin(), dists.begin()+K);

        vector<vector<int>> res;
        for (int i=0; i<K; i++) {
            res.push_back(points[dists[i].second]);
        }
        return res;

        // partial_sort(points.begin(), points.begin()+K, points.end(), [](vector<int>& p, vector<int>& q) {
        //     return p[0]*p[0]+p[1]*p[1] < q[0]*q[0]+q[1]*q[1];
        // });
        // return vector<vector<int>>(points.begin(), points.begin()+K);

        // nth_element(points.begin(), points.begin()+K-1, points.end(), [](vector<int>& p, vector<int>& q) {
        //     return p[0]*p[0]+p[1]*p[1] < q[0]*q[0]+q[1]*q[1];
        // });
        // return vector<vector<int>>(points.begin(), points.begin()+K);
 
    }
};
// @lc code=end

