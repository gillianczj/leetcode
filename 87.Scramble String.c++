//recursion without dp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) {
            return true;
        }
        if(s1.size() != s2.size()) {
            return false;
        }
        vector<int> count(256, 0);
        for(int i = 0; i < s1.size(); ++i) {
            ++count[s1[i]];
            --count[s2[i]];
        }
        for(auto n : count) {
            if(n != 0) {
                return false;
            }
        }
        for(int i = 1; i < s1.size(); ++i) {
            if((isScramble(s1.substr(0, i), s2.substr(0, i) && isScramble(s2.substr(i), s2.substr(i))) || (isScramble(s1.substr(0, i), s2.substr(s1.size() - i) && isScramble(s1.substr(i), s2.substr(0, s1.size() - i))))) {
                    return true;
                    }
        }
        return false;
    }
};
//dp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) {
            return true;
        }
        if(s1.size() != s2.size()) {
            return false;
        }
        int len = s1.size();
        bool dp[len][len][len];
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                dp[0][i][j] = (s1[i] == s2[j]);
            }
        }
        for(int k = 2; k <= len; ++k) {
            for(int i = 0; i < len; ++i) {
                for(int j = 0; j < len; ++j) {
                    dp[k - 1][i][j] = false;
                    for(int m = 1; m < k; ++m) {
                        if(dp[m - 1][i][j] && dp[k - m - 1][i + m][j + m]) {
                            dp[k - 1][i][j] = true;
                        }else if(dp[m - 1][i][j + k - m] && dp[k - m - 1][i + m][j]) {
                            dp[k - 1][i][j] = true;
                        }
                    }
                }
            }
        }
        return dp[len - 1][0][0];
    }
};
