//solution one iteration
class Solution {
public:
    int closestValue(TreeNode* root, int target) {
        int ret = root->val;
        while(root) {
            if(abs(ret - target) > abs(root->val - target)) {
                ret = root->value;
            }
            root = target > root->val ? root->right : root->left;
        }
        return ret;
    }
};

//solution two recursion
class Solution {
public:
    int closestValue(TreeNode* root, int target) {
        int a = root->val;
        TreeNode* t = target > root->val ? root->right ? root->left;
        if(!t) {
            return a;
        }
        int b = closestValue(t, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};
