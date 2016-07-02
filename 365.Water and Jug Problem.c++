class solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z == x || z == y) {
            return true;
        }
        if(z <= x + y && z % gcd(x, y) == 0) {
            return true;
        }
        return false;
    }
private:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};
