class solution {
public:
	ListNode* sortList(ListNode* head) {
		if(!head || !head->next) {
			return head;
		}
		//two pointers
		ListNode *fast = head;
		ListNode *slow = head;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		//divide to two lists
		fast = slow->next;
		slow->next = NULL;
		//divide and conquer
		ListNode *p1 = sortList(head);
		ListNode *p2 = sortList(fast);
	
		return merge(p1, p2);
	}
private:
	ListNode* merge(ListNode *p1, ListNode *p2) {
		if(!p1) {
			return p2;
		}else if(!p2) {
			return p1;		
		}

		ListNode *dummy = new ListNode(0);
		ListNode *p = dummy;

		while(p1 && p2) {
			if(p1->val < p2->val) {
				p->next = p1;
				p1 = p1->next;
			}else {
				p->next = p2;
				p2 = p2->next;
			}
			p = p->next;
		}
		//the remaining part
		if(p1) {
			p->next = p1;		
		}else {
			p->next = p2;			
		}
		//dont forget delete
		p = dummy->next;
		delete dummy;
		return p;
	}
};
