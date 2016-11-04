class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size() <= k) {
            return s.size();
        }
        int left = 0, maxLen = 1;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); ++i) {
            ++mp[s[i]];
            while(s.size() > k) {
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
