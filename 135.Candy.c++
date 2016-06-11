class solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.empty()) {
            return 0;
        }
        int n = ratings.size();
        vector<int> candy(n, 1);
        int sum = 0;
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }//from left to right
        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
                candy[i] = candy[i + 1] + 1;
            }
        }//from right to left
        for(int a : candy) {
            sum += a;
        }
        return sum;
    }
};
