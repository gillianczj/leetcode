class solution {
public:
    int climbStairs(int n) {
        vector<int> step(n, 0);
        if(n <= 1) {
            return n;
        }

        step[0] = 1;
        step[1] = 2;

        for(int i = 2; i < n; ++i) {
            step[i] = step[i - 1] + step[i - 2];
        }

        return step.back();
    }
};
