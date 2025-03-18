https://leetcode.com/problems/longest-valid-parentheses/
class Solution {
public:
    // time : O(n)
    // space: O(n) due to stk

    // you can do this ques in O(n) time and O(1) w/o using stk, how ? HW
    int longestValidParentheses(string s) {

        int maxSofar = 0;
        stack<int> stk; // stk will track indices of chars. not yet matched
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                // s[i] == ')'
                if (!stk.empty() and stk.top() != -1 and s[stk.top()] == '(') { // !stk.empty() condn is not needed
                    // ')' at ith index matches '(' at the top of the stk
                    stk.pop();
                    maxSofar = max(maxSofar, i - stk.top()); // stk.top() repr the index of the last unmatched char
                } else {
                    // ')' at the ith index will never match
                    stk.push(i);
                }
            }
        }

        return maxSofar;

    }
};