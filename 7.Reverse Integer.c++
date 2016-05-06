class solution {
public:
    int reverse(int x) {
        if(x == 0) {
            return x;
        }

        long rev = 0;
        while(x != 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        if(rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }//if overflow

        return rev;
    }
};
