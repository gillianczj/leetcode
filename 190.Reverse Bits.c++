class solution {
public:
    uint32_t reversetBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i = 0; i < 32; ++i) {
            if(n & 1) {
                ret = (ret << 1) +1;
            }else {
                ret = (ret << 1);
            }
            n = n >> 1;
        }
        return ret;
    }
};
