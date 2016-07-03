class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size() + 1);
        sum[0] = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum[i + 1] = sun[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
private:
    vector<int> sum;
};
