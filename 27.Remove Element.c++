class solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;//two pointers
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }   
};
