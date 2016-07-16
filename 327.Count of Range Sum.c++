class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int count = 0;
        long long sum = 0;
        multiset<long long> sums;
        sums.insert(0);
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            count += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return count;
    }
};
