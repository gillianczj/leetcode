class solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;//store numbers have alreadsy appeared
        while(n != 1) {
            int sum = 0;
            while(n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;//new n
            if(s.count(n)) {
                return false;//run in a cycle
            }else {
                s.insert(n);
            }
        }
        return true;
    }
};
