class solution {
public:
    int getSum(int a, int b) {
        if(b == 0) {//carry is 0
            return a;
        }
        int sum = a ^ b;//without carry;
        int carry = (a & b) << 1;//only carry;
        return getSum(sum, carry);
    }
};
