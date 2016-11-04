class Solution {
public:
    int lengthOfLongestSubstringTwoDistinc(string s) {
        if(s.size() < 3) {
            return s.size();
        }
        int left = 0, maxLen = 1;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); ++i) {
            ++mp[s[i]];
            while(mp.size() > 2) {
                if(--mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                ++left;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};
