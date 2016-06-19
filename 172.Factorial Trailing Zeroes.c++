class solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n) {//get the number of 5, 25, 125 ...
            ret += n / 5;
            n = n / 5;
        }
        return ret;
    }
};
