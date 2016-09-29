class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left) {
            return root;
        }
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        TreeNode* ret = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};
