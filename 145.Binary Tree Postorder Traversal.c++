//recursive
class solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorder(root, ret);
        return ret;
    }
private:
    void postorder(TreeNode* root, vector<int>& ret) {
        if(!root) {
            return;
        }
        postorder(root->left, ret);
        postorder(root->right, ret);
        ret.push_back(root->val);
    }
};
//non recursive
class solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        if(!root) {
            return ret;
        }
        s.push(root);
        TreeNode* last = root;//last node pushed into array
        while(!s.empty()) {
            TreeNode* temp = s.top();
            if((!temp->left && !temp->right) || temp->left == last || temp->right == last) {
                s.pop();//if temp has no child, then push it. OR the last pushed node is temp's child
                ret.push_back(temp->val);
                last = temp;
            }else {
                if(temp->right) {//push right first
                    s.push(temp->right);
                }
                if(temp->left) {//then push left
                    s.push(temp->left);
                }
            }
        }
        return ret;
    }
};
