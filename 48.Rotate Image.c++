class solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            return;
        }
        int start = 0, end = matrix.size() - 1;
        while(start < end) {
            for(int i = start; i < end; ++i) {
                int offset = i - start;
                int temp = matrix[start][start + offset];
                matrix[start][start + offset] = matrix[end - offset][start];
                matrix[end - offset][start] = matrix[end][end - offset];
                matrix[end][end - offset] = matrix[start + offset][end];
                matrix[start + offset][end] = temp;
            }
            ++start;
            --end;
        }
    }
};
