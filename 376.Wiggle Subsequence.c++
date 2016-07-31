class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        int count = 1;
        int preInc = 0;//1 means preDec, 2 means preInc
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i - 1] && (preInc == 0 || preInc == 1)) {
                ++count;
                preInc = 2;
            }else if(nums[i] < nums[i - 1] && (preInc == 0 || preInc == 2)) {
                ++count;
                preInc = 1;
            }
        }
        return count;
    }
};
