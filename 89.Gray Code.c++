class solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        if(n < 0) {
            return gray;
        }
        gray.push_back(0);
        int carry = 1;
        if(int i = 1; i <= n; ++i) {
            if(int j = gray.size() - 1; j >= 0; --j) {
                gray.push_back(gray[j] + carry);
            }
            carry <<= 1;
        }
        return gray;
    }
};
