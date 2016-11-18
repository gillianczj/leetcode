class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int ret = 0;
        int lower = INT_MIN, upper = INT_MAX;
        isValidBST(root, lower, upper, ret);
        return ret;
    }
private:
    bool isValidBST(TreeNode* root, int& lower, int& upper, int& ret) {
        if(!root) {
            return true;
        }
        int leftNode = 0, rightNode = 0;
        int leftLower = INT_MIN, leftUpper = INT_MAX;
        int rightLower = INT_MIN, rightUpper = INT_MAX;
        bool left = isValidBST(root->left, leftLower, leftUpper, leftNode);
        bool right = isValidBST(root->right, rightLower, rightUpper, rightNode);
        if(left && right) {
            if((!root->left || root->val > leftUpper) && (!root->right || root->val < rightLower)) {
                ret = leftNode + rightNode + 1;
                lower = root->left ? leftLower : root->val;
                upper = root->right ? rightUpper : root->val;
                return true;
            }
        }
        ret = max(leftNode, rightNode);
        return false;
    }
};
