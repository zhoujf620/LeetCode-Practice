/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 *
 * https://leetcode.com/problems/reducing-dishes/description/
 *
 * algorithms
 * Hard (72.00%)
 * Likes:    2177
 * Dislikes: 229
 * Total Accepted:    81.2K
 * Total Submissions: 107.9K
 * Testcase Example:  '[-1,-8,0,5,-7]'
 *
 * A chef has collected data on the satisfaction level of his n dishes. Chef
 * can cook any dish in 1 unit of time.
 * 
 * Like-time coefficient of a dish is defined as the time taken to cook that
 * dish including previous dishes multiplied by its satisfaction level i.e.
 * time[i] * satisfaction[i].
 * 
 * Return the maximum sum of like-time coefficient that the chef can obtain
 * after dishes preparation.
 * 
 * Dishes can be prepared in any order and the chef can discard some dishes to
 * get this maximum value.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: satisfaction = [-1,-8,0,5,-9]
 * Output: 14
 * Explanation: After Removing the second and last dish, the maximum total
 * like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
 * Each dish is prepared in one unit of time.
 * 
 * Example 2:
 * 
 * 
 * Input: satisfaction = [4,3,2]
 * Output: 20
 * Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: satisfaction = [-1,-4,-5]
 * Output: 0
 * Explanation: People do not like the dishes. No dish is prepared.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == satisfaction.length
 * 1 <= n <= 500
 * -1000 <= satisfaction[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(nums.begin(), nums.end());
        
        int res=0, total=0;
        for (int i=nums.size()-1; i>=0; --i) {
            total += nums[i];
            if (total <= 0) break;
             
            res += total;
        }
        return res;


        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> sums(nums.size());
        sums[n-1] = nums[n-1];
        for (int i=n-2; i>=0; --i) sums[i] = nums[i] + sums[i+1];

        int sum = 0;
        for (int i=0; i<n; ++i) sum += (i+1) * nums[i];

        int ans = sum;
        for (int i=0; i<n; ++i) {
            sum -= sums[i];
            ans = max(ans, sum);
        }
        return ans;

    }
};
// @lc code=end

