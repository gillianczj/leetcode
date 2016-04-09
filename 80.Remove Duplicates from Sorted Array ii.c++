#include <vector>

using namespace std;
class solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.empty()) {
			return 0;
		}//empty array
		if(nums.size() == 1) {
			return 1;
		}//only one element no duplicates

		bool dup = false;
		int j = 0;//two pointers

		for(int i = 1; i < (int)nums.size(); ++i) {
			if(nums[i] == nums[i - 1]) {
				if(dup) {continue;}//skip this number due two more than twice duplicates
				else {
					dup = true;
					nums[++j] = nums[i];//the second dup, set the flag
				}
			}else {
				dup = false;
				nums[++j] = nums[i];
			}
		}
		return j + 1;
	}
};

int main(){
    return 0;
}
