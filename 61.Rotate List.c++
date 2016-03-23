class solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if(k == 0 || !head) {
			return head;
		}
		int length = 0;
		ListNode *p = head;
		//get the length of the list
		while(p->next) {
			p = p->next;
			++length;
		}
		++length;
		//make it a circle
		p->next = head;
		//minimize k
		k = k % length;
		int n = length - k -1;
		//reset p
		p = head;
		//find the end and the beginning
		while(n) {
			p = p->next;
			--n;
		}
		//set the end and the beginning
		head = p->next;
		p->next = NULL;
		return head;
	}
};
