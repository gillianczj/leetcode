class solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); ++i) {
            if(dp[i]) {//only for now is breakable, then consider the following
                for(int len = 1; len + i < s.size() + 1; ++len) {
                    if(wordDict.count(s.substr(i, len))) {
                        dp[i + len] = true;
                    }
                }
            }
        }
        vector<string> ret;
        if(dp.back()) {
            helper(ret, s, wordDict, dp, "", 0);
        }
        return ret;
    }
private:
    void helper(vector<string> &ret, string &s, unordered_set<string> &wordDict, vector<bool> &dp, string cur, int idx) {
        string substr;
        for(int len = 1; len + idx < s.size() + 1; ++len) {
            if(wordDict.count(s.substr(idx, len)) && dp[idx + len]) {
                substr = s.substr(idx, len);
                if(idx + len < s.size()) {//not the end
                    helper(ret, s, wordDict, dp, cur + substr + " ", idx + len);
                }else {
                    ret.push_back(cur + substr);
                    return;
                }
            }
        }
    }
};
