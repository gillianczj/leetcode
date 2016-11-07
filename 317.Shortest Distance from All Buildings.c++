class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty()) {
            return -1;
        }
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> sum(row, vector<int>(col, 0));
        vector<vector<int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int val = 0;
        int ret = INT_MAX;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 1) {
                    vector<vector<int>> dist(row, vector<int>(col, 0));
                    ret = INT_MAX;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for(int k = 0; k < dirs.size(); ++k) {
                            int nx = x + dirs[k][0], ny = y + dirs[k][1];
                            if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == val) {
                                --grid[nx][ny];
                                dist[nx][ny] = dist[x][y] + 1;
                                sum[nx][ny] += dist[nx][ny];
                                ret = min(ret, sum[nx][ny]);
                                q.push({nx, ny});
                            }
                        }
                    }
                    --val;
                }
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
