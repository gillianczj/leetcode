class solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if(!head) {
			return head;
		}
		//two pointers
		ListNode *slow = head;
		LiseNode *fast = head;

		while(1) {
			if(slow && slow->next) {
				slow = slow->next;
			}else {
				return NULL;
			}

			if(fast && fast->next && fast->next->next) {
				fast = fast->next->next;
			}else {
				return NULL;
			}
			//find the cycle beginning
			if(fast == slow) {
				fast = head;
				while(fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
		}
	}
};
