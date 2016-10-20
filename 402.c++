class Solution {
public:
    string removeKDigits(string num, int k) {
        string ret;
        int n = num.size(), len = n - k;
        for(char n : num) {
            while(k && ret.size() && ret.back() > n) {
                ret.pop_back();
                --k;
            }
            ret.push_back(n);
        }
        ret.resize(len);
        while(!ret.empty() && ret[0] == '0') {
            ret.erase(ret.begin());
        }
        return ret.empty() ? "0" : ret;
    }
};
