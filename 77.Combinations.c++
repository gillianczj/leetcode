class solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> allSol;
        vector<int> allSol;
        if(k < 1 || k > n) {
            return allSol;
        }
        helper(allSol, sol, n, k, 1);
        return allSol;
    }
private:
    void helper(vector<vector<int>>& allSol, vector<int>& sol, int n, int k, int start) {
        if(k == 0) {
            allSol.push_back(sol);
            return;
        }

        for(int i = start; i <= n - k + 1; ++i) {//no duplicates
            sol.push_back(i);
            helper(allSol, sol, n, k - 1, i + 1);
            sol.pop_back();
        }
    }
};
