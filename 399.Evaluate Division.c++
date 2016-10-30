class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ret(queries.size(), -1);
        unordered_map<string, unordered_map<string, double>> mp;
        for(int i = 0; i < equations.size(); ++i) {
            mp[equations[i].first][equations[i].first] = 1;
            mp[equations[i].first][equations[i].second] = values[i];
            mp[equations[i].second][equations[i].second] = 1;
            mp[equations[i].second][equations[i].first] = 1.0 / values[i];
        }
        for(int i = 0; i < queries.size(); ++i) {
            pair<string, string> query = queries[i];
            if(!mp.count(query.first) || !mp.count(query.second)) {
                continue;
            }
            queue<pair<string, double> q;
            unordered_set<string> used;
            q.push({query.first, 1});
            used.insert(query.first);
            while(!q.empty()) {
                pair<string, double> temp = q.front();
                q.pop();
                if(query.second == temp.first) {
                    ret[i] = temp.second;
                    break;
                }
                for(auto node : mp[temp.first]) {
                    if(!used.count(node.first)) {
                        q.push({node.first, node.second});
                        used.insert(node.first);
                    }
                }
            }
        }
        return ret;
    }
};
