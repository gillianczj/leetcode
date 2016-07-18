class Solution {
public:
    bool isSelfCrossint(vector<int>& x) {
        if(x.size() < 4) {
            return false;
        }
        for(int i = 3; i < x.size(); ++i) {
            if(x[i] >= x[i - 2] && x[i - 3] >= x[i - 1]) {
                return true;
            }
            if(i >= 4 && x[i - 1] == x[i - 3] && x[i - 2] <= x[i] + x[i - 4]) {
                return true;
            }
            if(i >= 5 && x[i - 2] >= x[i - 4] && x[i - 2] <= x[i - 4] + x[i] && x[i - 3] >= x[i - 1] && x[i - 3] <= x[i - 1] + x[i - 5]) {
                return true;
            }
        }
        return false;
    }
};
