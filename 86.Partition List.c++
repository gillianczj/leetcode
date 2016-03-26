class solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if(!head || !head->next) {
			return head;
		}
		//two new head,one for first half,one for second half
		ListNode* d1 = new ListNode(0);
		ListNode* d2 = new ListNode(0);
		d1->next = head;

		ListNode* pre = d1;
		ListNode* start = head;
		ListNode* des = d2;

		while(start) {
			if(start->val < x) {
				//stay with d1
				start = start->next;
				pre = pre->next;
			}else {
				//go to d2
				pre->next = start->next;
				des->next = start;
				des = des->next;
				des->next = NULL;
				start = pre->next;
			}
		}
		//dont forget delete
		pre->next = d2->next;
		head = d1->next;
		delete d1, d2;
		return head;
	}
};
