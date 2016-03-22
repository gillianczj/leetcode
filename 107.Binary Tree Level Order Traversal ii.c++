class solution {
public:
	//do reverse after Binary Tree Level Order Traversal
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if(!root) {
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		vector<int> cur;

		while(!q.empty()) {
			TreeNode* temp = q.front();
			q.pop();
			if(temp) {
				if(temp->left) {
					q.push(temp->left);
				}
				if(temp->right) {
					q.push(temp->right);
				}
				cur.push_back(temp->val);
				continue;
			}
			if(!temp) {
				if(!q.empty()) {
					q.push(NULL);
				}
				ret.push_back(cur);
				cur.clear();
				continue;
			}
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
