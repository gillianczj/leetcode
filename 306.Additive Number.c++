class solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) {
            return false;
        }
        for(int i = 1; i < num.size(); ++i) {
            for(int j = i + 1; j < num.size(); ++j) {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - 1);//always left >=1 number
                long long d1 = stoll(s1);
                long long d2 = stoll(s2);
                long long next = d1 + d2;
                string nexts = to_string(next);
                string cur = s1 + s2 + nexts;
                while(cur.size() < num.size()) {
                    d1 = d2;
                    d2 = next;
                    next = d1 + d2;
                    nexts = to_string(next);
                    cur += nexts;
                }
                if(cur == num) {
                    return true;
                }
            }
        }
        return false;
    }
};
