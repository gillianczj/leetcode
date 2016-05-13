class solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty()) {
            return ret;
        }

        vector<string> dict({" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string comb;
        find(digits, ret, dict, comb, 0);
        return ret;
    }
private:
    void find(string &digits, vector<string> &ret, vector<string> &dict, string &comb, int index) {//backtracking
        if(index == digits.size()) {
            ret.push_back(comb);
            return;
        }

        string cur = dict[digits[index] - '0'];
        for(auto a : cur) {
            comb.push_back(a);
            find(digits, ret, dict, comb, index + 1);
            comb.pop_back();
        }
    }
};
