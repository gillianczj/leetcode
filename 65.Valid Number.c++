class Solution {
public:
    bool isNumber(string s) {
        bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ') {
                if(i < n - 1 && s[i + 1] != ' ' && (num || doc || exp || sign)) {
                    return false;
                }
            }else if(s[i] == '+' || s[i] == '-') {
                if(i > 0 && s[i - 1] != ' ' && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
                sign = true;
            }else if(s[i] == '.') {
                if(dot || exp) {
                    return false;
                }
                dot = true;
            }else if(s[i] == 'e' || s[i] == 'E') {
                if(!num || exp) {
                    return false;
                }
                exp = true;
                numAfterE = false;
            }else if(s[i] >= '0' && s[i] <= 9) {
                num = true;
                numAfterE = true;
            }else {
                return false;
            }
        }
        return num && numAfterE;
    }
};
