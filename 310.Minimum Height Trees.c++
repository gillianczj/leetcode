class solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        if(n == 1) {
            ret.push_back(0);
            return ret;
        }
        unordered_map<int, int> degree;
        unordered_map<int, vector<int>> graph;
        for(auto e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
            ++degree[e.first];
            ++degree[e.second];
        }
        queue<int> q;
        for(unordered_map<int, int>::iterator it = degree.begin(); it != degree.end(); ++it) {
            if(it->second == 1) {
                q.push(it->first);
            }
        }
        while(n > 2) {
            int m = q.size();
            for(int i = 0; i < m; ++i) {
                int temp = q.front();
                q.pop();
                --n;
                for(auto n : graph[temp]) {
                    --degree[n];
                    if(degree[n] == 1) {
                        q.push(n);
                    }
                }
            }
        }
        while(!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
