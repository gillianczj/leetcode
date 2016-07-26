//solution one
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
            });
        for(auto p : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), p.second);
            if(it == dp.end()) {
                dp.push_back(p.second);
            }else {
                *it = p.second;
            }
        }
        return dp.size();
    }
};

//solution two
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int ret = 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++i) {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
