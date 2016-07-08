class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) {
            return 1;
        }
        a %= 1337;
        int lastBit = b.back();
        b.pop_back();
        return (superPow(superPow(a, b), 10) * superPow(a, lastBit)) % 1337;
    }
private:
    int superPow(int a, int b) {
        if(b == 0) {
            return 1;
        }
        int ret = 1;
        for(int i = 0; i < b; ++i) {
            ret = (ret * a) % 1337;//mod every time
        }
        return ret;
    }
};
