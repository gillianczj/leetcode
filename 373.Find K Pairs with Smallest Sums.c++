//solution one
struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first + a.second < b.first + b.second;
    }
};
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ret;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i = 0; i < min((int)nums1.size(), k); ++i) {
            for(int j = 0; j < min((int)nums2.size(), k); ++j) {
                if(pq.size() < k) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                }else {
                    if(nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
                        pq.pop();
                        pq.push(make_pair(nums1[i], nums2[j]));
                    }
                }
            }
        }
        while(!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};

//solution two
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int, int> ret;
        multimap<int, pair<int, int>> mp;
        for(int i = 0; i < min((int)nums1.size(), k); ++i) {
            for(int j = 0; j < min((int)num2.size(), k); ++j) {
                mp.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            ret.push_back(it->second);
            if(--k == 0) {
                return ret;
            }
        }
        return ret;
    }
};
