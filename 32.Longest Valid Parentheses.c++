//DP
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2) {
            return 0;
        }
        int n = s.size();
        int maxLen = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            int j = i - 2 - dp[i - 1];
            if(s[i - 1] == '(' || j < 0 || s[j] == ')') {
                dp[i] = 0;
            }else {
                dp[i] = dp[i - 1] + 2 + dp[j];
                maxLen = max(dp[i], maxLen);
            }
        }
        return maxLen;
    }
};
