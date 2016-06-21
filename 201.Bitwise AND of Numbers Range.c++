//solution 1
class solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m != n) {//the last bits AND must be 0
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return m << i;
    }
};
//solution 2
class solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n > m) {
            n = n & (n - 1);//discard the least 1
        }
        return n;
    }
};
