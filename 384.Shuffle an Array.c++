class Solution {
public:
    Solution(vector<int> nums) {
        origin = nums;
    }

    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {
        vector<int> ret = origin;
        for(int i = 0; i < ret.size(); ++i) {
            int t = rand() % ret.size();
            swap(ret[i], ret[t]);
        }
        return ret;
    }
private:
    vector<int> origin;
};
