class Solution {
public:
    bool isPowerOfFour(int num) {
        double ans = log10(num) / log10(4);
        return ans == int(ans);
    }
};
