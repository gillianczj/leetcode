class solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m + n - 1;//the total last index
		int j = m - 1;//nums1 last index
		int k = n - 1;//nums2 last index
		//from back to front
		while(i >= 0) {
			if(j >= 0 && k >= 0) {
				if(nums1[j] >= nums2[k]) {
					nums1[i--] = nums1[j--];
				}else {
					nums1[i--] = nums2[k--];
				}
			}else {
				while(j >= 0) {
					nums1[i--] = nums1[j--];
				}
				while(k >= 0) {
					nums1[i--] = nums2[k--];
				}
			}
		}	
	}
};
