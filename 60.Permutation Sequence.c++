class solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> fact(n, 1);
        vector<char> nums(n, '1');

        for(int i = 1; i < n; ++i) {
            fact[i] = i * fact[i - 1];
            nums[i] = i + '1';
        }

        --k;//significant

        for(int i = n - 1; i >= 0; --i) {
            int j = k / fact[i];
            k %= fact[i];
            ret.push_back(nums[j]);
            nums.erase(nums.begin() + j);
        }

        return ret;
    }
};
