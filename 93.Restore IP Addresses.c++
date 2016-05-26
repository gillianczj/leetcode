class solution {
public:
    vector<string> restoreIPAdressed(string s) {
        vector<string> ret;
        for(int i = 1; i <= 3; ++i) {
            for(int j = 1; j <= 3; ++j) {
                for(int k = 1; k <= 3; ++k) {
                    for(int l = 1; l <= 3; ++l) {
                        if(i + j + k + l == s.size()) {
                            string a(s.begin(), s.begin() + i);
                            string b(s.begin() + i, s.begin() + i + j);
                            string c(s.begin() + i + j, s.begin() + i + j + k);
                            string d(s.begin() + i + j + k, s.begin() + i + j + k + l);
                            if(isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                                ret.push_back(a + "." + b + "." + c + "." + d);
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
private:
    bool isValid(string x) {
        if(x.size() != 1 && x[0] == '0') {
            return false;
        }
        int sum = 0;
        for(auto a : x) {
            sum = sum * 10 + a - '0';
        }
        return sum < 256;
    }
};
