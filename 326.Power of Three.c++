class Solution {
public:
    bool isPowerOfThree(int n) {
        double ans = log10(n) / log10(3);
        return ans - int(ans) == 0;
    }
};
