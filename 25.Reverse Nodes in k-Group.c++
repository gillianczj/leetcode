class solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if(k < 2) {
			return head;
		}

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* p = dummy;

		while(p->next && p->next->next) {
			ListNode* pre = p->next;//first node, stay unchanged
			ListNode* cur = pre->next;//second node,reversed
			int count = 0;//count
			while(cur && count < k - 1) {//k-1 is because cur starts from the second one, pre is the first one
				ListNode* temp = cur->next;
				cur->next = pre;
				pre = cur;
				cur = temp;
				++count;
			}

			if(count == k - 1) {// k nodes reversed
				ListNode* temp = p->next;
				p->next->next = cur;
				p->next = pre;
				p = temp;
			}else {//less than k nodes
				cur = pre->next;
				pre->next = NULL;
				while(cur != p->next) {//undo reverse
					ListNode* temp = cur->next;
					cur->next = pre;
					pre = cur;
					cur = temp;
				}
				break;
			}
		}

		p = dummy->next;
		delete dummy;
		return p;
	}
};
