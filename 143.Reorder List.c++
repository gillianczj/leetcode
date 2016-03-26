class solution {
public:
	void reorderList(ListNode* head) {
		if(!head || !head->next || !head->next->next) {
			return;
		}

		ListNode* mid = findMid(head);
		ListNode* right = reverseMid(mid);
		ListNode* left = head;

		while(right != mid) {
			ListNode* temp = right;	
			right = right->next;
			temp->next = left->next;
			left->next = temp;
			left = left->next->next;
		}
	}
private:
	ListNode* findMid(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	
	ListNode* reverseMid(ListNode* mid) {
		if(!mid || !mid->next) {
			return mid;
		}

		ListNode* pre = mid;
		ListNode* cur = mid->next;

		while(cur) {
			ListNode* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		//mid need a new next pointer
		mid->next = NULL;
		return pre;
	}
};
