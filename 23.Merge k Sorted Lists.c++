class solution {
public:
	//since priority queue is max heap by default, so we need a new comparator	
	struct comp {
		bool operator()(ListNode* p, ListNode* q) {
			return p->val > q->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, comp> pq;
		//beiginning of the new linked list
		ListNode* dummy = new ListNode(0);
		ListNode* p = dummy;
		//populate the priority queue
		for(auto a : lists) {
			//push if not NULL			
			if(a) {
				pq.push(a);
			}
		}

		while(!pq.empty()) {
			p->next = pq.top();
			pq.pop();
			p = p->next;
			//if not end, bring it back
			if(p->next) {
				pq.push(p->next);
			}
		}
		//dont forget delete
		p = dummy->next;
		delete dummy;
		return p;
	}
};
