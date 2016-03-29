class solution {
public:
	RandomListNode* copyRandomList(RandomListNode* head) {
		if(!head) {
			return NULL;
		}
		//hash table
		unordered_map<RandomListNode*, RandomListNode*> mp;
		RandomListNode* p1 = head;
		RandomListNode* p2 = new RandomListNode(head->label);
		mp[head] = p2;

		while(p1) {
			//next exist
			if(p1->next) {
				if(mp.count(p1->next)) {
					p2->next = mp[p1->next];
				}else {
					p2->next = new RandomListNode(p1->next->label);
					mp[p1->next] = p2->next;
				}
			}
			//random exist
			if(p1->random) {
				if(mp.count(p1->random)) {
					p2->random = mp[p1->random];
				}else {
					p2->random = new RandomListNode(p1->random->label);
					mp[p1->random] = p2->random;
				}
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		return mp[head];
	}
};
