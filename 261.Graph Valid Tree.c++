class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        unordered_set<int> visited;
        queue<int> q;
        for(auto e : edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        q.push(0);
        visited.insert(0);
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(auto n : graph[t]) {
                if(visited.count(n)) {
                    return false;
                }
                q.push(n);
                visited.insert(n);
                graph[n].erase(t);
            }
        }
        return visited.size() == n;
    }
};
