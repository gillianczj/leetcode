class solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        int i = 0, j = 0, maxLen = 0;
        unordered_set<char> sub;
        while(i < s.size() && j < s.size()) {
            if(!sub.count(s[j])) {
                sub.insert(s[j++]);
            }else {
                maxLen = max(maxLen, j - i);
                sub.erase(s[i++]);
            }
        }
        maxLen = max(maxLen, j - i);//the last part
        return maxLen;
    }
};
