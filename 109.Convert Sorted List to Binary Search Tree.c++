class solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		ListNode* cur = head;
		//calculate the length of the list
		while(cur) {
			cur = cur->next;
			++len;
		}

		return helper(head, 0, len - 1);
	}
private:
	TreeNode* helper(ListNode* head, int start, int end) {
		if(start > end) {
			return NULL;
		}

		ListNode* p = head;
		int mid = start + (end - start) / 2;
		//find the root point
		for(int i = start; i < mid; ++i) {
			p = p->next;
		}
		//recursive
		TreeNode* left = helper(head, start, mid - 1);
		TreeNode* right = helper(p->next, mid + 1, end);
		TreeNode* root = new TreeNode(p->val);

		root->left = left;
		root->right = right;

		return root;
	}
};
