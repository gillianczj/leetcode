class solution {
public:
    int canComplete(vector<int> &gas, vector<int> &cost) {
        int start = 0, cur = 0, all = 0;
        for(int i = 0; i < cost.size(); ++i) {
            all += (gas[i] - cost[i]);
            cur += (gas[i] - cost[i]);
            if(cur < 0) {
                start = i + 1;
                cur = 0;//new start
            }
        }
        if(all < 0) {
            return -1;
        }
        return start;
    }
};
