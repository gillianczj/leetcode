class solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        int xor_first = 0;
        int xor_second = 0;
        for(auto n : nums) {
            xor_first ^= n;
        }
        int count = 0;
        for(; count < 32; ++count) {
            if((xor_first >> count) & 1 == 1) {
                break;
            }//find where two num diff
        }
        for(auto n : nums) {
            if((n >> count) & 1 == 1) {
                xor_second ^= n;
            }
        }
        ret.push_back(xor_second);
        ret.push_back(xor_second ^ xor_first);
        return ret;
    }
};
