class solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if(!head || !head->next) {
			return head;
		}
		//dummy node to record the beginning
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = dummy;
		//do the swap here
		while(p->next && p->next->next) {
			ListNode *first = p->next;
			ListNode *second = p->next->next;
			first->next = second->next;
			second->next = first;
			p->next = second;
			p = p->next->next;
		}
		//dont forget the delete
		ListNode *temp = dummy->next;
		delete dummy;
		return temp;
	}
};
