class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(auto word : dictionary) {
            string key = word[0] + to_string(word.size() - 2) + word.back();
            mp[key].insert(word);
        }
    }

    bool isUnique(string word) {
        string k = word[0] + to_string(word.size() - 2) + word.back();
        return mp[k].count(word) == mp[k].size();
    }
private:
    unordered_map<string, unordered_set<string>> mp;
};
