//recursive
class solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		preorder(root, ret);
		return ret;
	}
private:
	void preorder(TreeNode* root, vector<int>& ret) {
		if(!root) {
			return;
		}
		ret.push_back(root->val);
		preorder(root->left, ret);
		preorder(root->right, ret);
	}
};

//non recursive
class solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        if(!root) {
            return ret;
        }
        s.push(root);
        while(!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            ret.push_back(temp->val);
            if(temp->right) {//push right first
                s.push(temp->right);
            }
            if(temp->left) {//then push left
                s.push(temp->left);
            }
        }
        return ret;
    }
};
