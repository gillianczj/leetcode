class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        unordered_map<string, int> mp;
        set<int> s;
        for(int i = 0; i < words.size(); ++i) {
            mp[words[i]] = i;
            s.insert(words[i].size());
        }
        for(int i = 0; i < words.size(); ++i) {
            string temp = words[i];
            int l = temp.size();
            reverse(temp.begin(), temp.end());
            if(mp.count(temp) && mp[temp] != i) {//the reversed exists and is not itself
                ret.push_back({i, mp[temp]});
            }
            auto end = s.find(l);
            for(auto iter = s.begin(); iter != end; ++iter) {
                int d = *iter;
                if(isValid(temp, 0, l - d - 1) && mp.count(temp.substr(l - d))) {
                    ret.push_back({i, mp[temp.substr(l - d)]});
                }
                if(isValid(temp, d, l - 1) && mp.count(temp.substr(0, d))) {
                    ret.push_back({mp[temp.substr(0, d)], i});
                }
            }
        }
        return ret;
    }
private:
    bool isValid(string& s, int left, int right) {
        while(left < right) {
            if(s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};
