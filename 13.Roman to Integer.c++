class solution {
public:
    int romanToInt(string s) {
        if(s.empty()) {
            return 0;
        }

        unordered_map<char, int> dict({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C',100}, {'D', 500}, {'M', 1000}});

        int ret = 0;
        for(int i = 0; i < s.size(); ++i) {
            ret += dict[s[i]];
            if(dict[s[i]] < dict[s[i + 1]] && i + 1 < s.size()) {
                ret -= 2 * dict[s[i]];
            }//first one is less than second one, then they should be combined
        }
        return ret;
    }
};
