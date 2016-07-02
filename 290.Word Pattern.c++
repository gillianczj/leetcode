class solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream in(str);
        unordered_map<char, string> mp;
        int i = 0;
        for(string word; in >> word; ++i) {
            if(mp.count(pattern[i])) {//the char is in the map
                if(mp[pattern[i]] != word) {//char and word do not match
                    return false;
                }
            }else {
                for(unordered_map<char, string>::iterator it = mp.begin(); it != mp.end(); ++it) {
                    if(it->second == word) {//char is not in the map but this very word matches other char's
                        return false;
                    }
                }
                mp[pattern[i]] = word;
            }
        }
        return i == pattern.size();//make sure size matches
    }
};
