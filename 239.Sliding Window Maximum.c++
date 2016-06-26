class solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> q;
        for(int i = 0; i < nums.size(); ++i) {
            if(!q.empty() && i - k == q.front()) {//get rid of extra front
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();//keep the max in the front
            }
            q.push_back(i);
            if(i >= k - 1) {//window starts
                ret.push_back(nums[q.front()]);
            }
        }
        return ret;
    }
};
