class solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};//32 bits
        int ret = 0;
        for(int i = 0; i < 32; ++i) {
            for(int n : nums) {
                if((n >> i) & 1) {
                    ++count[i];
                }
            }
            ret += (count[i] % 3) << i;
        }
        return ret;
    }
};
