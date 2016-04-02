class solution {
public:
	int findCelebrity(int n) {
		int i = 0;
		//find the candidate
		while(i < n) {
			int j = i + 1;
			while(j < n && !know(i, j)) {
				++j;
			}
			if(j == n) {break;}
			i = j;
		}

		//verify the candidate
		for(int k = 0; k < n; ++k) {
			if(k != i) {
				if(!know(k, i) || know(i, k)) {
					return -1;
				}
			}
		}

		return i;
	}
};
