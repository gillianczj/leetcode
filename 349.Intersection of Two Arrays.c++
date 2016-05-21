class solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.empty() || nums2.empty()) {
            return ret;
        }

        unordered_set<int> s;

        for(int a : nums1) {
            s.insert(a);
        }

        for(int b : nums2) {
            if(s.count(b)) {
                ret.push_back(b);
                s.erase(b);
            }
        }

        return ret;
    }
};
