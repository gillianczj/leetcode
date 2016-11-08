class Solution {
public:
    vector<int> numIsland2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ret;
        if(m <= 0 || n <= 0) {
            return ret;
        }
        vector<int> root(m * n, -1);
        int count = 0;
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto p : positions) {
            int id = n * p.first + p.second;
            root[id] = id;
            ++count;
            for(auto d : dirs) {
                int x = p.first + d[0], y = p.second + d[1];
                int curId = n * x + y;
                if(x < 0 || x >= m || y < 0 || y >= n || root[curId] == -1) {
                    continue;
                }
                int newId = find(root, curId);
                if(id != newId) {
                    root[id] = newId;
                    id = newId;
                    --count;
                }
            }
            ret.push_back(count);
        }
        return ret;
    }
private:
    int find(vector<int>& root, int id) {
        while(id != root[id]) {
            root[id] = root[root[id]];
            id = root[id];
        }
        return id;
    }
};
