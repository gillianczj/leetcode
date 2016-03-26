class solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(!head) {
			return head;
		}
		//in case the head is removed
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		ListNode* p = head;
		//p n-1 steps ahead
		while(n - 1) {
			p = p->next;
			--n;
		}
		//find the node to be removed
		while(p && p->next) {
			pre = pre->next;
			cur = cur->next;
			p = p->next;
		}
		//delete cur
		pre->next = cur->next;
		//dont forget delete
		head = dummy->next;
		delete dummy;
		return head;
	}
};
