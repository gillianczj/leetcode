class solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pa = headA;
		ListNode *pb = headB;

		int lengthA = 0, lengthB = 0;
		//length of A and B
		while(pa) {
			pa = pa->next;
			++lengthA;
		}

		while(pb) {
			pb = pb->next;
			++lengthB;
		}

		//difference between lengthA and lengthB
		int n = abs(lengthA - lengthB);

		if(lengthA >= lengthB) {
			//reset two pointers			
			pa = headA;
			pb = headB;
			while(n) {
				pa = pa->next;
				--n;
			}
		}

		if(lengthA < lengthB) {
			//reset two pointers
			pa = headA;
			pb = headB;
			while(n) {
				pb = pb->next;
				--n;
			}
		}

		while(pa != pb) {
			pa = pa->next;
			pb = pb->next;
		}

		return pa;
	}
};
