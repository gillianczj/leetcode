class solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return true;
        }
        if(!root->left && !root->right) {
            return true;
        }
        return valid(root, LONG_MIN, LONG_MAX);
    }
private:
    bool valid(TreeNode* root, long minVal, long maxVal) {
        if(!root) {
            return true;
        }
        if(root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        return valid(root->left, minVal, root->val) && valid(root->right, root->val, maxVal);
    }
};

//use inorder traversal
class solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> seq;
        stack<TreeNode*> s;
        while(root) {//go to the leftest node
            s.push(root);
            root = root->left;
        }
        while(!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            seq.push_back(temp->val);
            if(temp->right) {
                temp = temp->right;
                while(temp) {
                    s.push(temp);
                    temp = temp->left;
                }
            }
        }
        if(ret.size() <= 1) {
            return true;
        }
        for(int i = 1; i < seq.size(); ++i) {
            if(seq[i] <= seq[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
