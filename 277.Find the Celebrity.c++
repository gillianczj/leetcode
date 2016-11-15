//solution one
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

//solution two
class Solution {
public:
	int findCelebrity(int n) {
		int cele = 0;
		for(int i = 0; i < n; ++i) {
			if(know(cele, i)) {
				cele = i;
			}
		}
		for(int i = 0; i < n; ++i) {
			if(cele != i && (!know(i, cele) || know(cele, i))) {
				return -1;
			}
		}
		return cele;
	}
};