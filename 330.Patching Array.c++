class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0, idx = 0;
        long known = 1;
        while(known <= n) {
            if(idx < nums.size() && nums[idx] <= known) {
                known += nums[idx];
            }else {
                known <<= 1;
                ++count;
            }
        }
        return count;
    }
};
