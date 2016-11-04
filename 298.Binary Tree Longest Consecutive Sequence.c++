class solution {
public:
	int longestConsecutive(TreeNode* root) {
		if(!root) {return 0;}
		return find(root, 0, root->val - 1);
	}
private:
	int find(TreeNode* root, int curLen, int preVal) {
		if(!root) {return curLen;}
		int length = preVal + 1 == root->val ? curLen + 1 : 1;
		return max(length, max(find(root->left, length, root->val), find(root->right, length, root->val)));
	}
};
//another version
class Solution {
public:
	int longestConsecutive(TreeNode* root) {
		if(!root) {
			return 0;
		}
		int ret = 0;
		dfs(root, 1, ret);
		return ret;
	}
private:
	void dfs(TreeNode* root, int len, int& ret) {
		ret = max(ret, len);
		if(root->left) {
			if(root->left->val == root->val + 1) {
				dfs(root->left, len + 1, ret);
			}else {
				dfs(root->left, 1, ret);
			}
		}
		if(root->right) {
			if(root->right->val == root->val + 1) {
				dfs(root->right, len + 1, ret);
			}else {
				dfs(root->right, 1, ret);
			}
		}
	}
};
