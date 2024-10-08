/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (62.45%)
 * Likes:    1681
 * Dislikes: 156
 * Total Accepted:    104.8K
 * Total Submissions: 167.7K
 * Testcase Example:  '["cat","bat","rat"]\n"the cattle was rattled by the battery"'
 *
 * In English, we have a concept called root, which can be followed by some
 * other word to form another longer word - let's call this word successor. For
 * example, when the root "an" is followed by the successor word "other", we
 * can form a new word "another".
 * 
 * Given a dictionary consisting of many roots and a sentence consisting of
 * words separated by spaces, replace all the successors in the sentence with
 * the root forming it. If a successor can be replaced by more than one root,
 * replace it with the root that has the shortest length.
 * 
 * Return the sentence after the replacement.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled
 * by the battery"
 * Output: "the cat was rat by the bat"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 * Output: "a a b c"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] consists of only lower-case letters.
 * 1 <= sentence.length <= 10^6
 * sentence consists of only lower-case letters and spaces.
 * The number of words in sentence is in the range [1, 1000]
 * The length of each word in sentence is in the range [1, 1000]
 * Every two consecutive words in sentence will be separated by exactly one
 * space.
 * sentence does not have leading or trailing spaces.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // sort(dict.begin(), dict.end(), [](string& a, string& b) {
        //     return a.size() < b.size();
        // });
        // vector<vector<string>> v(26);
        // for (string word: dict) v[word[0]-'a'].push_back(word);
        
        unordered_set<string> hset(dict.begin(), dict.end());
        string ans;
        istringstream in(sentence);
        string word;
        while (in >> word) {
            string prefix;
            for (int len=0; len<=word.size(); ++len) {
                prefix = word.substr(0, len);
                if (hset.count(prefix)) break;
            }
            ans += prefix + " ";
        }
        ans.pop_back();
        return ans;    
    }
};
// @lc code=end

