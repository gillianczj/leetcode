class solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& bulidings) {
        multimap<int, int> line;
        vector<pair<int, int>> ret;
        for(auto c : bulidings) {
            line.emplace(c[0], c[2]);
            line.emplace(c[1], -c[2]);
        }
        multiset<int> h;
        for(multimap<int, int>::iterator it = line.begin(); it != line.end(); ++it) {
            int key = it->first;
            while(it != line.end() && it->first == key) {
                if(it->second > 0) {
                    h.insert(it->second);
                }else {
                    h.erase(h.find(-it->second));
                }
                ++it;
            }
            --it;
            int height = *h.rbegin();
            if(ret.empty() || height != ret.back().second) {
                ret.push_back(make_pair(it->first, height));
            }
        }
        return ret;
    }
};
