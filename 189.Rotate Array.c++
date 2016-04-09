class solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() || k == 0 || k % nums.size() == 0) {return;}
        k = k % nums.size();//minimize k
        vector<int>::iterator it = nums.begin() + k;
        reverse(nums.begin(), nums.end());//reverse the whole array
        reverse(nums.begin(), it);//reverse the front section
        reverse(it, nums.end());//reverse the back section
    }
};
