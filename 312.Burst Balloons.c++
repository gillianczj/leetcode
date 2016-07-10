class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i + k <= n + 1; ++i) {
                int j = i + k - 1;
                for(x = i; x <= j; ++x) {
                    dp[i][j] = max(dp[i][j], dp[i][x - 1] + nums[i - 1] * nums[x] * nums[j + 1] + dp[x + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};
