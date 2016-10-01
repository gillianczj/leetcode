class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)  {
        if(numerator == 0) {
            return "0";
        }
        string ret;
        if(numerator < 0 ^ denominator < 0) {
            ret += "-";
        }
        long long n = (long long)numerator;
        long long d = (long long)denominator;
        n = abs(n);
        d = abs(d);
        ret += to_string(n / d);
        n = n % d;
        if(n == 0) {
            return ret;
        }
        ret += ".";
        unordered_map<int, int> mp;
        while(n) {
            if(mp.count(n)) {
                ret.insert(mp[n], 1, '(');
                ret.push_back(')');
                break;
            }
            mp[n] = ret.size();
            n *= 10;
            ret += to_string(n / d);
            n = n % d;
        }
        return ret;
    }
};
