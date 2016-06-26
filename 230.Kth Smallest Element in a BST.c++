class solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int ret = 0;
        while(cur || !s.empty()) {
            if(!cur) {//get to the end
                cur = s.top();
                s.pop();
                if(--k == 0) {
                    ret = cur->val;
                    break;
                }
                cur = cur->right;
            }else {
                s.push(cur);
                cur = cur->left;
            }
        }
        return ret;
    }
};
