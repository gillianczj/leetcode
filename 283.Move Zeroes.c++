class solution {
public:
	void moveZeroes(vector<int>& nums) {
		//two pointers , one is resource, one is destination
		int i = 0;//resourse
		int j = 0;//destination
		while(i < nums.size()) {
			if(nums[i] != 0) {
				nums[j++] = nums[i++];
			}else {
				++i;
			}
		}
		while(j < nums.size()) {
			nums[j++] = 0;
		}
	}
};
