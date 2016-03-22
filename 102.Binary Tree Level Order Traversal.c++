class solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if(!root) {
			return ret;
		}
		//queue store TreeNode*
		queue<TreeNode*> q;
		q.push(root);
		//NULL marks the end of one level
		q.push(NULL);
		vector<int> cur;

		while(!q.empty()) {
			TreeNode* temp = p.front();
			p.pop();
			//not end
			if(temp) {
				if(temp->left) {
					p.push(temp->left);
				}
				if(temp->right) {
					p.push(temp->right);	
				}
				cur.push_back(temp->val);
				continue;
			}
			//end
			if(!temp) {
				//not end
				if(!p.empty()) {
					//push the mark
					p.push(NULL);
				}
				ret.push_back(cur);
				//reset cur
				cur.clear();
				continue;
			}
		}

		return ret;
	}
}
