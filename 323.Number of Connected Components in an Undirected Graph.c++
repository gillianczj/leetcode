class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ret = n;
        vector<int> root;
        for(int i = 0; i < n; ++i) {
            root[i] = i;
        }
        for(auto node : edges) {
            int x = find(root, node.first), y = find(root, node.second);
            if(x != y) {
                --ret;
                root[y] = x;
            }
        }
        return ret;
    }
private:
    int find(vector<int>& root, int i) {
        while(i != root[i]) {
            i = root[i];
        }
        return i;
    }
};
