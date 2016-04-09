class solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = col - 1;//right upper cornor
        while(i < row && j >= 0) {
            if(target == matrix[i][j]) {
                return true;
            }else if(target > matrix[i][j]) {
                ++i;//go down
            }else {
                --j;//go left
            }
        }
        return false;
    }
};
