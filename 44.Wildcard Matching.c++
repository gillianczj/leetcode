class Solution {
public:
    bool isMatch(string s, string p) {
        int tempi = 0, tempj = 0;
        int i = 0, j = 0;
        bool has_star = false;
        while(i < s.size() && (has_star || j < p.size())) {
            if(j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                ++i;
                ++j;
            }else if(j < p.size() && p[j] == '*') {
                has_star = true;
                if(j + 1 == p.size()) {
                    return true;
                }
                tempi = i;
                tempj = ++j;
            }else {
                if(!has_star) {
                    return false;
                }
                i = ++tempi;//move forward
                j = tempj;//go back to origin
            }
        }
        while(j < p.size() && p[j] == '*') {
            ++j;
        }
        return (i == s.size() && j = p.size());
    }
};
