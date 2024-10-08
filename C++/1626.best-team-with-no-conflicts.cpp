/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 *
 * https://leetcode.com/problems/best-team-with-no-conflicts/description/
 *
 * algorithms
 * Medium (41.22%)
 * Likes:    1063
 * Dislikes: 31
 * Total Accepted:    23.3K
 * Total Submissions: 56.2K
 * Testcase Example:  '[1,3,5,10,15]\n[1,2,3,4,5]'
 *
 * You are the manager of a basketball team. For the upcoming tournament, you
 * want to choose the team with the highest overall score. The score of the
 * team is the sum of scores of all the players in the team.
 * 
 * However, the basketball team is not allowed to have conflicts. A conflict
 * exists if a younger player has a strictly higher score than an older player.
 * A conflict does not occur between players of the same age.
 * 
 * Given two lists, scores and ages, where each scores[i] and ages[i]
 * represents the score and age of the i^th player, respectively, return the
 * highest overall score of all possible basketball teams.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
 * Output: 34
 * Explanation: You can choose all the players.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: scores = [4,5,6,5], ages = [2,1,2,1]
 * Output: 16
 * Explanation: It is best to choose the last 3 players. Notice that you are
 * allowed to choose multiple people of the same age.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: scores = [1,2,3,5], ages = [8,9,10,1]
 * Output: 6
 * Explanation: It is best to choose the first 3 players. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= scores.length, ages.length <= 1000
 * scores.length == ages.length
 * 1 <= scores[i] <= 10^6
 * 1 <= ages[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> nums;
        for (int i=0; i<n; ++i) nums.push_back(vector<int>{scores[i], ages[i]});
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        });

        // for (int i=0; i<n; ++i) cout << nums[i][0] << " " << nums[i][1] << endl;

        vector<int> dp(n, 0);
        dp[0] = nums[0][0];
        int ans = nums[0][0];
        
        for (int i=1; i<n; ++i) {

            int maxSum = 0;
            for (int j=i-1; j>=0; --j) {
                if (nums[j][0] <= nums[i][0])
                    maxSum = max(maxSum, dp[j]);
            }
            dp[i] = maxSum + nums[i][0];
            ans = max(ans, dp[i]);
        }

        return ans;

    }
};
// @lc code=end

