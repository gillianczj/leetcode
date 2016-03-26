class solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if(!head || !head->next) {
			return head;
		}
		//odd and even node to be done
		ListNode* odd = head;
		ListNode* even = head->next;
		//swap here
		while(even && even->next) {
			ListNode* temp = odd->next;
			odd->next = even->next;
			even->next = even->next->next;
			odd->next->next = temp;
			odd = odd->next;
			even = even->next;
		}

		return head;
	}
};
