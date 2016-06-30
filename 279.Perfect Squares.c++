//solution one
class solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i) {
            for(int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);
            }
        }
        return dp.back();
    }
};

//solution two
class solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0) {//times 4 
            n /= 4;
        }
        if(n % 8 == 7) {//4
            return 4;
        }
        for(int a = 0; a * a <= n; ++a) {//1&2
            int b = sqrt(n - a * a);
            if(a * a + b * b == n) {
                return !!a + !!b;//double not gives number of squares not zero
            }
        }
        return 3;//3
    }
};
