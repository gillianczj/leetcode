class solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if(!root) {return ret;}
		//need two stacks
		stack<TreeNode*> *cur = new stack<TreeNode*>();
		stack<TreeNode*> *next = new stack<TreeNode*>();
		cur->push(root);
		bool left2right = true;
	
		while(!cur->empty()) {
			vector<int> sol;
			while(!cur->empty()) {
				TreeNode* temp = cur->top();
				cur->pop();
				sol.push_back(temp->val);
				if(left2right) {//to implement zigzag
					if(temp->left) {next->push(temp->left);}
					if(temp->right) {next->push(temp->right);}
				}else {
					if(temp->right) {next->push(temp->right);}
					if(temp->left) {next->push(temp->left);}
				}
			}
			ret.push_back(sol);
			sol.clear();

			stack<TreeNode*> *tmp = cur;//change the cur pointer
			cur = next;
			next = tmp;
			
			left2right = !left2right;
		}
		delete cur;
		delete next;
		return ret;
	}
};
