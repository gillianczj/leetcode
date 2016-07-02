class solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) {
            return {};
        }
        int curMax = 1;
        int idx = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); ++i) {
            mp[i].push_back(nums[i]);
        }
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0) {
                    if(mp[j].size() + 1 > mp[i].size()) {
                        mp[i] = mp[j];
                        mp[i].push_back(nums[i]);
                    }
                    if(mp[i].size() > curMax) {
                        curMax = mp[i].size();
                        idx = i;
                    }
                }
            }
        }
        return mp[idx];
    }
};
