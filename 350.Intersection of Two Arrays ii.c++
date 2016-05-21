class solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.empty() || nums2.empty()) {
            return ret;
        }

        unordered_map<int, int> m;

        for(int a : nums1) {
            if(!m.count(a)) {
                m[a] = 1;
            }else {
                ++m[a];
            }
        }

        for(int b : nums2) {
            if(!m.count(b) || m[b] == 0) {
                continue;
            }else {
                ret.push_back(b);
                --m[b];
            }
        }

        return ret;
    }
};
