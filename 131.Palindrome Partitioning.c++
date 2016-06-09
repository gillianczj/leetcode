class solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allSol;
        vector<string> sol;
        find(s, 0, sol, allSol);
        return allSol;
    }
private:
    void find(string &s, int start, vector<string> &sol, vector<vector<string>> &allSol) {
        if(start == s.size()) {
            allSol.push_back(sol);
            return;
        }
        for(int i = start; i < s.size(); ++i) {//backtracking
            if(valid(s, start, i)) {
                sol.push_back(s.substr(start, i - start + 1));
                find(s, i + 1, sol, allSol);
                sol.pop_back();
            }
        }
    }
    bool valid(string &s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
