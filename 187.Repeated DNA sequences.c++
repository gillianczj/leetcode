class solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_set<string> bef;
        unordered_set<string> aft;
        int n = s.size();
        for(int i = 0; i < n - 9; ++i) {
            string sub = s.substr(i, 10);
            if(!bef.count(sub)) {//do not exist
                bef.insert(sub);
            }else {
                if(!aft.count(sub)) {//already exist
                    ret.push_back(sub);
                    aft.insert(sub);
                }
            }
        }
        return ret;
    }
};
