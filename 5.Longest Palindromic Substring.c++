class Solution {
public:
    string longestPalindorme(string s) {
        if(s.size() < 2) {
            return s;
        }
        int n = s.size();
        bool isPal[n][n] = {false};
        int maxLen = 1;
        int start = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j >= 0; --j) {
                if(i == j) {
                    isPal[j][i] == true;
                }else if(j + 1 == i && s[j] == s[i]) {
                    isPal[j][i] = true;
                }else if(j + 1 < i && s[j] == s[i] && isPal[j + 1][i - 1]) {
                    isPal[j][i] = true;
                }
                if(isPal[j][i]) {
                    if(i - j + 1 > maxLen) {
                        maxLen = i - j + 1;
                        start = j;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
