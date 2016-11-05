class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int ret = 0;
        isUnival(root, -1, ret);
        return ret;
    }
private:
    bool isUnival(TreeNode* root, int val, int& ret) {
        if(!root) {
            return true;
        }
        if(!isUnival(root->left, root->val, ret) || !isUnival(root->right, root->val, ret)) {
            return false;
        }
        ++ret;
        return root->val == val;
    }
};
