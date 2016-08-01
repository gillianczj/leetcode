class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) {
            return 0;
        }
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(pq.size() < k) {
                    pq.push(matrix[i][j]);
                }else if(matrix[i][j] < pq.top()) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};
