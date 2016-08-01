class Solution {
public:
    int maxSumSubMatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int ret = INT_MIN;
        for(int i = 0; i < col; ++i) {
            vector<int> sum(row, 0);
            for(int j = i; j < col; ++j) {
                set<int> st{0};
                int curSum = 0, curMax = 0;
                for(int x = 0; x < row; ++x) {
                    sum[x] += matrix[x][j];
                    curSum += sum[x];
                    auto it = st.lower_bound(curSum - k);
                    if(it != st.end()) {
                        curMax = max((curSum - *it), curMax);
                    }
                    st.insert(curSum);
                }
                ret = max(ret, curMax);
                if(ret == k) {
                    return ret;
                }
            }
        }
        return ret;
    }
};
