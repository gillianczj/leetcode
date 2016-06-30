class solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> allSol;
        string sol;
        helper(num, target, 0, 0, sol, allSol);
        return allSol;
    }
private:
    void helper(string &num, int target, long long diff, long long curNum, string sol, vector<string> &allSol) {
        if(num.size() == 0 && curNum == target) {
            allSol.push_back(sol);
        }
        for(int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if(cur.size() > 1 && cur[0] == '0') {
                return;
            }
            string remain = num.substr(i);
            if(sol.empty()) {
                helper(remain, target, stoll(cur), stoll(cur), cur, allSol);
            }else {
                helper(remain, target, stoll(cur), curNum + stoll(cur), sol + "+" + cur, allSol);//+
                helper(remain, target, -stoll(cur), curNum - stoll(cur), sol + "-" + cur, allSol);//-
                helper(remain, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), sol + "*" + cur, allSol);
            }
        }
    }
};
