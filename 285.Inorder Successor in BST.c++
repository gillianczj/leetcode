class Solution {
public:
    TreeNode* inorderSuccess(TreeNode* root, TreeNode* p) {
        return helper(root, p, NULL);
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* upper) {
        if(!root) {
            return upper;
        }
        if(root->val > p->val) {
            return helper(root->left, p, root);
        }else {
            return helper(root->right, p, upper);
        }
    }
}
