class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ret;
        if(strings.empty()) {
            return ret;
        }
        unordered_map<string, multiset<string>> mp;
        for(auto s : strings) {
            string temp = "";
            for(auto c : s) {
                temp += to_string((c + 26 - s[0]) % 26);
            }
            mp[temp].insert(s);
        }
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            ret.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return ret;
    }
};
