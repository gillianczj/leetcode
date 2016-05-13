class solution {
public:
    vector<string> generateParantheses(int n) {
        vector<string> allSol;
        string sol;
        find(allSol, sol, n, 0, 0);
        return allSol;
    }
private:
    void find(vector<string> &allSol, string &sol, int n, int nleft, int nright) {
        if(nleft == n && nright == n) {
            allSol.push_back(sol);
            return;
        }

        if(nleft < n) {
            sol.push_back('(');
            find(allSol, sol, n, nleft + 1, nright);
            sol.pop_back();
        }

        if(nright < nleft) {
            sol.push_back(')');
            find(allSol, sol, n, nleft, nright + 1);
            sol.pop_back();
        }
    }
};
