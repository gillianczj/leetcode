class solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allSol;
        if(nums.empty()) {
            return allSol;
        }
        vector<int> sol;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());//sort to avoid duplicates
        find(nums, allSol, sol, used);
        return allSol;
    }
private:
    void find(vector<int>& nums, vector<vector<int>>& allSol, vector<int>& sol, vector<bool>& used) {
        if(sol.size() == nums.size()) {
            allSol.push_back(sol);
            return;
        } 

        for(int i = 0; i < nums.size(); ++i) {
            if(used[i]) {
                continue;
            }

            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            sol.push_back(nums[i]);
            find(nums, allSol, sol, used);
            sol.pop_back();
            used[i] = false;
        }
    }
};
