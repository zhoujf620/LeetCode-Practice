/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (30.39%)
 * Likes:    554
 * Dislikes: 1438
 * Total Accepted:    175.4K
 * Total Submissions: 577.1K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level. For more
 * information, see: Absolute path vs relative path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */
#include<string>
#include<vector>
#include<sstream>
using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string res, ch;
        vector<string> stack;
        stringstream ss(path);
        while (getline(ss, ch, '/')) {
            if(ch=="" || ch==".") 
                continue;
            else if (ch=="..") {
                if (!stack.empty()) 
                    stack.pop_back();
            }
            else 
                stack.push_back(ch);
        }
        string ans = "/";
        for (int i=0; i<stack.size(); ++i) {
            ans += stack[i];
            if (i!=stack.size()-1) ans += "/";
        }
        return ans;
    }
};
// @lc code=end

