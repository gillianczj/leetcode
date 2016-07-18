class Solution {
public:
    vector<string> findItinerary(vector<pair<int, int>>& tickets) {
        vector<string> ret;
        if(tickets.empty()) {
            return ret;
        }
        unordered_map<string, map<string, int>> mp;
        for(const auto& ticket : tickets) {
            ++mp[ticket.first][ticket.second];
        }
        string start = "JFK";
        ret.push_back(start);
        dfs(mp, ret, start, tickets.size() + 1);
        return ret;
    }
private:
    bool dfs(unordered_map<string, map<string, int>>& mp, vector<string>& ret, string start, const int& len) {
        if(ret.size() == len) {
            return true;
        }
        for(auto iter = mp[start].begin(); iter != mp[start].end(); ++iter) {
            if(iter->second != 0) {
                --iter->second;
                ret.push_back(iter->first);
                if(dfs(mp, ret, iter->first, len)) {
                    return true;
                }
                ret.pop_back();
                ++iter->second;
            }
        }
        return false;
    }
};
