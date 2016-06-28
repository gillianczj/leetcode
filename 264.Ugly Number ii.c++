class solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ret(1, 1);
        int idx2 = 0, idx3 = 0, idx5 = 0;
        while(ret.size() < n) {
            int ugly2 = ret[idx2] * 2;
            int ugly3 = ret[idx3] * 3;
            int ugly5 = ret[idx5] * 5;
            int min_ugly = min(ugly2, min(ugly3, ugly5));
            if(min_ugly == ugly2) {
                ++idx2;
            }
            if(min_ugly == ugly3) {
                ++idx3;
            }
            if(min_ugly == ugly5) {
                ++idx5;
            }
            ret.push_back(min_ugly);
        }
        return ret.back();
    }
};
