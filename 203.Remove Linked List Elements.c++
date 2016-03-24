class solution {
public:
	ListNode* removeElements(ListNode *head, int val) {
		if(!head) {
			return head;
		}
		//in case head is removed
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = dummy;

		while(p->next) {
			if(p->next->val == val) {
				p->next = p->next->next;
			}else {
				p = p->next;
			}
		}
		//dont forget delete
		p = dummy->next;
		delete dummy;
		return p;
	}
};
