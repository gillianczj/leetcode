class solution {
public:
    int singleNumber(vector<int> &nums) {
        int ret = 0;
        for(int a : nums) {
            ret ^= a;
        }
        return ret;//xor
    }
};
