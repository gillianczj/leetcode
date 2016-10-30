//brute force
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty()) {
            return 0;
        }
        int row = image.size();
        int col = image[0].size();
        int left = y, right = y, up = x, down = x;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(image[i][j] == '1') {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        return (right - left + 1) * (down - up + 1);
    }
};

//dfs
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty()) {
            return 0;
        }
        int left = y, right = y, up = x, down = x;
        vector<vector<bool>>& used(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, used, x, y, left, right, up, down);
        return (right - left + 1) * (down - up + 1);
    }
private:
    void dfs(vector<vector<char>>& image, vector<vector<bool>>& used, int x, int y, int& left, int& right, int& up, int& down) {
        used[x][y] = true;
        left = min(left, y);
        right = max(right, y);
        up = min(up, x);
        down = max(down, x);
        if(x - 1 >= 0 && image[x - 1][y] == '1' && !used[x - 1][y]) {
            dfs(image, used, x - 1, y, left, right, up, down);
        }
        if(x + 1 < image.size() && image[x + 1][y] == '1' && !used[x + 1][y]) {
            dfs(image, used, x + 1, y, left, right, up, down);
        }
        if(y - 1 >= 0 && image[x][y - 1] == '1' && !used[x][y - 1]) {
            dfs(image, used, x, y - 1, left, right, up, down);
        }
        if(y + 1 < image[0].size() && image[x][y + 1] == '1' && !used[x][y + 1]) {
            dfs(image, used, x, y + 1, left, right, up, down);
        }
    }
};

//binary search
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty()) {
            return 0;
        }
        int row = image.size();
        int col = image[0].size();
        int up = search(image, x, 0, "up");
        int down = search(image, x, row - 1, "down");
        int left = search(image, y, 0, "left");
        int right = search(image, y, col - 1, "right");
        return (right - left + 1) * (down - up + 1);
    }
private:
    int search(vector<vector<char>>& image, int i, int j, string opt) {
        int row = image.size();
        int col = image[0].size();
        if(opt == "up") {
            int start = j, end = i;
            while(start < end) {
                int mid = start + (end - start) / 2;
                bool has = false;
                for(int i = 0; i < col; ++i) {
                    if(image[mid][i] == '1') {
                        has = true;
                        break;
                    }
                }
                if(has) {
                    end = mid;
                }else {
                    start = mid + 1;
                }
            }
            return start;
        }else if(opt == "down") {
            int start = i, end = j;
            while(start < end) {
                int mid = start + (end - start) / 2;
                bool has = false;
                for(int i = 0; i < col; ++i) {
                    if(image[mid][i] == '1') {
                        has = true;
                        break;
                    }
                }
                if(has) {
                    start = mid;
                }else {
                    end = mid - 1;
                }
            }
            return start;
        }else if(opt == "left") {
            int start = j, end = i;
            while(start < end) {
                int mid = start + (end - start) / 2;
                bool has = false;
                for(int i = 0; i < row; ++i) {
                    if(image[i][mid] == '1') {
                        has = true;
                        break;
                    }
                }
                if(has) {
                    end = mid;
                }else {
                    start = mid + 1;
                }
            }
            return start;
        }else {
            int start = i, end = j;
            while(start < end) {
                int mid = start + (end - start) / 2;
                bool has = false;
                for(int i = 0; i < row; ++i) {
                    if(image[i][mid] == '1') {
                        has = true;
                        break;
                    }
                }
                if(has) {
                    start = mid;
                }else {
                    end = mid - 1;
                }
            }
            return start;
        }
    }
};
