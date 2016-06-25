class solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty() || nums.size() == 1) {
            return false;
        }
        vector<pair<int, int>> p;
        for(int i = 0; i < nums.size(); ++i) {
            p.push_back(make_pair(nums[i], i));
        }
        sort(p.begin(), p.end(), comp);
        return search(p, k, t);
    }
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }
    bool search(vector<pair<int, int>> &p, int k, int t) {
        int po = 0;
        while(po < p.size()) {
            int i = po + 1;
            while(i < p.size()) {
                if(abs(long(p[po].first) - long(p[i].first)) <= t && abs(long(p[po].second) - long(p[i].second)) <= k) {
                    return true;
                }else {
                    if(abs(long(p[po].first) - long(p[i].first)) > t) {
                        break;
                    }else {
                        ++i;
                    }
                }
            }
            ++po;
        }
        return false;
    }
};
