class solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp;
        mp['6'] = '9';
        mp['9'] = '6';
        mp['0'] = '0';
        mp['8'] = '8';
        mp['1'] = '1';
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            if(!mp.count(num[start]) || !mp.count(num[end]) || mp[num[start]] != num[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};
