struct Node {
    int value;
    int index;
    int count;
    Node(int val, int idx) : value(val), index(idx), count(0) {}
    bool operator <= (const Node& other) const {
        return value <= other.value;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        vector<Node> myNums;
        vector<Node> temp(nums.size(), Node(0, 0));
        for(int i = 0; i < nums.size(); ++i) {
            myNums.push_back(Node(nums[i], i));
        }
        merge_sort(myNums, 0, nums.size() - 1, temp);
        for(auto node : myNums) {
            ret[node.index] = node.count;
        }
        return ret;
    }
private:
    void merge_sort(vector<Node>& myNums, int left, int right, vector<Node>& temp) {
        if(left < right) {
            int mid = (left + right) >> 1;
            merge_sort(myNums, left, mid, temp);
            merge_sort(myNums, mid + 1, right, temp);
            combine(myNums, left, mid, right, temp);
        }
    }
    void combine(vector<Node>& myNums, int ls, int le, int rs, vector<Node>& temp) {
        int rs = le + 1;
        int ts = ls;
        int len = re - ls + 1;
        int x = rs;
        while(ls <= le && rs <= re) {
            if(myNums[ls] <= myNums[rs]) {
                temp[ts] = myNums[ls];
                temp[ts].count += rs - x;
                ++ts;
                ++ls;
            }else {
                temp[ts++] = myNums[rs++];
            }
        }
        while(ls <= le) {
            temp[ts] = myNums[ls];
            temp[ts].count += rs - x;
            ++ts;
            ++ls;
        }
        while(rs <= re) {
            temp[ts++] = myNums[rs++];
        }
        for(int i = 0; i < len; ++i, --re) {
            myNums[re] = temp[re];
        }
    }
};
