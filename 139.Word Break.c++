class solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j >= 0; --j) {
                if(dp[j] && wordDict.count(s.substr(j, i - j + 1))) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp.back()
    }
};
