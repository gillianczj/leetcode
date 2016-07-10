class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ret(n, INT_MAX);
        ret[0] = 1;
        int num = primes.size();
        vector<int> idx(num, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < num; ++j) {
                ret[i] = min(ret[i], ret[idx[j]] * primes[j]);
            }
            for(int j = 0; j < num; ++j) {
                if(ret[j] == ret[idx[j]] * primes[j]) {
                    ++idx[j];
                }
            }
        }
        return ret.back();
    }
};
