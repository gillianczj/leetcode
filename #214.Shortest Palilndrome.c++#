class solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(n == 0 || n == 1) {
            return s;
        }
        int len = 0;
        string s1 = s;
        reverst(s1.begin(); s1.end());
        for(int i = n; i > 0; --i) {
            if(s.substr(0, i) == s1.substr(n - i, i)) {
                len = i;
                break;
            }
        }
        return s1.substr(0, n - len) + s;
    }
};
