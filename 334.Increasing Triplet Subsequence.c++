class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }
        int n1 = INT_MAX, n2 = INT_MAX;
        for(int n : nums) {
            if(n <= n1) {
                n1 = n;
            }else if(n <= n2) {
                n2 = n;
            }else {
                return true;
            }
        }
        return false;
    }
};
