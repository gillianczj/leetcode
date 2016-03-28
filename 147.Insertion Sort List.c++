class solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		ListNode* temp = head;
		
		while(temp) {
			ListNode* cur = temp;
			ListNode* p = dummy;
			temp = temp->next;
			//find the right positon
			while(p->next && p->next->val <= cur->val) {
				p = p->next;
			}
			//insertion
			cur->next = p->next;
			p->next = cur;
		}

		temp = dummy->next;
		delete dummy;
		return temp;
	}
};
