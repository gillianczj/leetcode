class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0) {
            return s.size() == 0;
        }
        if(p[1] == '*') {
            while(s[0] == p[0] || (p[0] == '.' && s.size() > 0)) {
                if(isMatch(s, p.substr(2))) {
                    return true;
                }
                s = s.substr(1);
            }
            return isMatch(s, p.substr(2));
        }else {
            if(s[0] == p[0] || (p[0] == '.' && s.size() > 0)) {
                return isMatch(s.substr(1), p.substr(1));
            }
            return false;
        }
    }
};
