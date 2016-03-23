class solution {
public:
	bool hasCycle(ListNode* head) {
		if(!head) {
			return false;
		}	
		//two pointers
		ListNode *slow = head;
		ListNode *fast = head;

		while(slow && fast && fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) {
				return true;
			}
		}
		return false;
	}
};
