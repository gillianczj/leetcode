class solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.empty() ? 0 : nums[0];
        }

        vector<int> dp1(nums.size() - 1, 0);
        vector<int> dp2(nums.size() - 1, 0);

        //without the last one
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size() - 1; ++i) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        //without the first one
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for(int i = 3; i < nums.size(); ++i) {
            dp[i - 1] = max(dp[i - 2], dp[i - 3] + nums[i]);
        }

        return dp1.back() > dp2.back() ? dp1.back() : dp2.back();
    }
}
