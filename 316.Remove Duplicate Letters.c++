class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[26] = {0};
        bool used[26] = {false};
        string ret = "0";
        for(auto c : s) {
            ++m[c - 'a'];
        }
        for(auto c : s) {
            --m[c - 'a'];
            if(used[c - 'a']) {
                continue;
            }
            while(c < ret.back() && m[ret.back() - 'a']) {
                used[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            ret += c;
            used[c - 'a'] = true;
        }
        return ret.substr(1);
    }
};
