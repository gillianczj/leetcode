class solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = new ListNode(0);
		ListNode* p = result;
		int carry = 0;
		while(l1 || l2) {
			int val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
			carry = val / 10;
			val = val % 10;
			p->next  = new ListNode(val);
			p = p->next;
			if(l1) {
				l1 = l1->next;
			}
			if(l2) {
				l2 = l2->next;
			}
		}
		//if carry is not zero
		if(carry != 0) {
			p->next = new ListNode(carry);
		}

		p = dummy->next;
		delete dummy;
		return p;
	}
};
