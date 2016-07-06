class NumArray {
public:
    NumArray(vector<int>& nums) {
        c.resize(nums.size() + 1);
        m_nums = nums;
        for(int i = 0; i < nums.size(); ++i) {
            add(i + 1, nums[i]);
        }
    }

    int lowBit(int pos) {
        return pos & (-pos);
    }

    void add(int pos, int val) {
        while(pos < c.size()) {
            c[pos] += val;
            pos += lowBit(pos);
        }
    }

    int sum(int pos) {
        int ret = 0;
        while(pos > 0) {
            ret += c[pos];
            pos -= lowBit(pos);
        }
    }

    void update(int i, int val) {
        int ori = m_nums[i];
        int diff = val - ori;
        m_nums[i] = val;
        add(i + 1, diff);
    }

    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
private:
    vector<int> m_nums;
    vector<int> c;
};
