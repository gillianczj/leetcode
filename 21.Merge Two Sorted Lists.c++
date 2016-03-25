class solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(!l1) {
			return l2;
		}else if(!l2) {
			return l1;
		}
		//to determine the beginning
		ListNode* dummy = new ListNode(0);
		ListNode* p = dummy;

		while(l1 && l2) {
			if(l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			}else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}

		if(l1) {
			p->next = l1;
		}else if(l2) {
			p->next = l2;
		}
		//dont forget delete
		p = dummy->next;
		delete dummy;
		return p;
	}
};
