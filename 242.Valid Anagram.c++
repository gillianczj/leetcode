class solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        int nums[26] = {0};
        for(int i = 0; i < s.size(); ++i) {
            nums[s[i] - 'a'] += 1;
            nums[t[i] - 'a'] -= 1;
        }
        for(auto n : nums) {
            if(n != 0) {
                return false;
            }
        }
        return true;
    }
};
