//solution one
class solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while(n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt == 1;
    }
};

//solution two
class solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n - 1)));
    }
};
