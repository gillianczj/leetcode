class solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
private:
    void helper(TreeNode* root, int cur, int &sum) {
        if(!root) {
            return;
        }
        cur = cur * 10 + root->val;
        if(!root->left && !root->right) {//end
            sum += cur;
        }
        if(root->left) {
            helper(root->left, cur, sum);
        }
        if(root->right) {
            helper(root->right, cur, sum);
        }
    }
};
