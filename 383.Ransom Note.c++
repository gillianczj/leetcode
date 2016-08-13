class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.empty()) {
            return ransomNote.empty();
        }
        unordered_map<char, int> mp;
        for(auto c : magazine) {
            ++mp[c];
        }
        for(auto c : ransomNote) {
            if(mp.find(c) == mp.end() || mp[c] == 0) {
                return false;
            }
            --mp[c];
        }
        return true;
    }
};
