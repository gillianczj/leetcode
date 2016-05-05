class solution {
public:
    int rob(TreeNode* root) {
        return dfs(root).first;
    }
private:
    pair<int, int> dfs(TreeNode* root) {
        pair<int, int> dp = make_pair(0, 0);
        if(root) {
            pair<int, int> left = dfs(root->left);
            pair<int, int> right = dfs(root->right);
            //dynamic programming
            dp.second = left.first + right.first;
            dp.first = max(dp.second, left.second + right.second + root->val);
        }
        return dp;
    }
}
