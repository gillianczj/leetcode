class solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int total = m + n;
		if(total % 2 == 1) {//odd
			return find(nums1, m, nums2, n, total / 2 + 1);//find the total/2+1 th element
		}else {
			return (find(nums1, m, nums2, n, total / 2) + find(nums1, m, nums2, n, total / 2 + 1)) / 2;
		}
	}
private:
	double find(vector<int>& nums1, int size1, vector<int>& nums2, int size2, int k) {
		int m = nums1.size(), n = nums2.size();
		int start1 = m - size1, start2 = n - size2;
		if(size1 > size2) {//keep the smaller one as nums1
			return find(nums2, size2, nums1, size1, k);
		}
		if(size1 == 0) {
			return nums2[start2 + k - 1];
		}else if(k == 1) {
			return min(nums1[start1], nums2[start2]);
		}else {
			int pa = min(k / 2, size1);
			int pb = k - pa;
			if(nums1[start1 + pa - 1] <= nums2[start2 + pb - 1]) {//discard the first part of the smaller one
				return find(nums1, size1 - pa, nums2, size2, k - pa);
			}else {
				return find(nums1, size1, nums2, size2 - pb, k - pb);
			}
		}
	}
};
