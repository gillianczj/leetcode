class solution {
public:
	ListNode* reverseList(ListNode* head) {
		if(!head) {
			return head;
		}
		//new end
		ListNode* p = NULL; 
		while(head) {
			ListNode* temp = head->next;
			head->next = p;
			p = head;
			head = temp;
		}
		return p;
	}
};
