class solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if(!head || !head->next) {
			return head;
		}
		//in case head is removed
		ListNode *dummy = new ListNode(0);
		dummy->next  = head;
		ListNode *pre = dummy;
		ListNode *cur = head;
		//is duplicates?
		bool isD = false;
		while(cur) {
			if(cur->next && cur->val == cur->next->val) {
				cur->next = cur->next->next;
				isD = true;
			}else if(isD) {
				pre->next = cur->next;
				cur = pre->next;
				isD = false;
			}else {
				pre = cur;
				cur = cur->next;			
			}
		}

		ListNode *temp = dummy->next;
		//dont forget delete
		delete dummy;
		return temp;
	}
};
