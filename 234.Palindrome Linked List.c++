class solution {
public:
	bool isPalindrome(ListNode *head) {
		if(!head || !head->next) {
			return true;
		}
		//use stack
		stack<int> s;
		s.push(head->val);
		//two pointers
		ListNode *slow = head;
		ListNode *fast = head;
		//first half
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			s.push(slow->val);
		}

		//if odd
		if(!fast->next) {
			s.pop();
		}
		//second half
		while(slow->next) {
			slow = slow->next;
			int temp = s.top();
			s.pop();
			if(temp != slow->val) {
				return false;
			}
		}
		return true;
	}
};
