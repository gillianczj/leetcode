class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) {
            return 1;
        }
        int ret = 0;
        for(int i = 1; i <= n; ++i) {
            ret += count(i);
        }
        return ret;
    }
private:
    int count(int n) {
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return 10;
        }
        int ret = 1;
        for(int i = 9; i >= 11 - n; --i) {
            ret *= i;
        }
        return ret * 9;
    }
};
