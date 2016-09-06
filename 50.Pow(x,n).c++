class Solution {
public:
    double myPow(double x, int n) {
        long long m = (long long) n;
        if(x == 0) {
            return 0;
        }
        if(x == 1 || m == 0) {
            return 1;
        }
        if(m == 1) {
            return x;
        }
        if(m < 0) {
            m = -m;
            x = 1/x;
        }
        double temp = 1;
        if(m % 2 == 1) {
            temp = x;
        }
        return temp * myPow(x * x, n / 2);
    }
};
