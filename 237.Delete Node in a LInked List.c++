class solution {
public:
	void deleteNode(ListNode* node) {
		ListNode *post = node->next;
		node->val = post->val;
		node->next = post->next;
	}
};
