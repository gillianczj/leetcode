class solution {
public:
    int titleToNumber(string s) {
        if(s.empty()) {
            return 0;
        }
        int ret = 0;
        for(auto a : s) {
            ret = ret * 26 + a - 64;
        }
        return ret;
    }
};
