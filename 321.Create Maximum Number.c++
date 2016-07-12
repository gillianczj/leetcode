class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ret;
        for(int i = max(0, k - n); i <= min(m, k); ++i) {
            vector<int> max1 = maxVector(nums1, i);
            vector<int> max2 = maxVector(nums2, k - i);
            ret = max(ret, mergeVector(max1, max2));
        }
        return ret;
    }
private:
    vector<int> maxVector(vector<int>& nums, int k) {
        int drop = nums.size() - k;
        vector<int> ret;
        for(auto num : nums) {
            while(drop && !ret.empty() && ret.back() < num) {
                --drop;
                ret.pop_back();
            }
        }
        ret.resize(k);//get first k
        return ret;
    }
    vector<int> mergeVector(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        while(nums1.size() + nums2.size()) {
            vector<int>& temp = nums1 > nums2 ? nums1 : nums2;
            ret.push_back(temp[0]);
            temp.erase(temp.begin());
        }
        return ret;
    }
};
