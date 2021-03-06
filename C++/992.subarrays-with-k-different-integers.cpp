/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 *
 * https://leetcode.com/problems/subarrays-with-k-different-integers/description/
 *
 * algorithms
 * Hard (46.39%)
 * Likes:    677
 * Dislikes: 13
 * Total Accepted:    19K
 * Total Submissions: 41K
 * Testcase Example:  '[1,2,1,2,3]\n2'
 *
 * Given an array A of positive integers, call a (contiguous, not necessarily
 * distinct) subarray of A good if the number of different integers in that
 * subarray is exactly K.
 * 
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 * 
 * Return the number of good subarrays of A.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,2,1,2,3], K = 2
 * Output: 7
 * Explanation: Subarrays formed with exactly 2 different integers: [1,2],
 * [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,2,1,3,4], K = 3
 * Output: 3
 * Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
 * [2,1,3], [1,3,4].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= A.length
 * 1 <= K <= A.length
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0;
        
		vector<int> hash(nums.size()+1, 0);
        for(int left=0, right=0, cnt=0, last=0; right<nums.size(); right++) {
            if(hash[nums[right]]==0)
                cnt++;
            hash[nums[right]]++;
            
            if (cnt<k) continue;
            
            while(cnt > k) {
                hash[nums[left]]--;
                if (hash[nums[left]]==0)
                    cnt--;
                left ++;
                last = left;
            }
            
            while(hash[nums[left]] > 1) {
                hash[nums[left]]--;
                left ++;
            }
            ans += left-last+1;    
        }
        return ans;
    }
};
// @lc code=end

