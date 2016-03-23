class solution {
public:
	ListNode* reverseBetween(ListNode *head, int m, int n) {
		if(m == n) {
			//no need to reverse
			return head;
		}
		//in case head is reversed
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *start = dummy;//first node to be reversed
		ListNode *end = dummy;//last node to be reversed
		ListNode *begin = dummy;//unchanged last one
		int num = n - m;//# of reversion
		while(m-1) {
			begin = begin->next;
			--m;
		}
		start = begin->next;
		while(n) {
			end = end->next;
			--n;
		}
		ListNode *pre = end->next;//first node after end
		begin->next = end;

		while(num >= 0) {
			ListNode *temp = start->next;
			start->next = pre;
			pre = start;
			start = temp;
			--num;
		}

		ListNode *p = dummy->next;
		delete dummy;
		return p;
	}
};
