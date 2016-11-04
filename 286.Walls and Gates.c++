class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) {
            return;
        }
        for(int i = 0; i < rooms.size(); ++i) {
            for(int j = 0; j < rooms[0].size(); ++j) {
                if(rooms[i][j] == 0) {
                    dfs(rooms, i - 1, j, 1);
                    dfs(rooms, i + 1, j, 1);
                    dfs(rooms, i, j - 1, 1);
                    dfs(rooms, i, j + 1, 1);
                }
            }
        }
    }
private:
    void dfs(vector<vector<int>>& rooms, int x, int y, int depth) {
        if(x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] <= depth) {
            return;
        }
        rooms[x][y] = depth;
        dfs(rooms, x - 1, y, depth + 1);
        dfs(rooms, x + 1, y, depth + 1);
        dfs(rooms, x, y - 1, depth + 1);
        dfs(rooms, x, y + 1, depth + 1);
    }
};
