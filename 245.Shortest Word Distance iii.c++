class solution {
public:
	int shortestWordDistance(vector<string>& words, string word1, string word2) {
		int idx1 = -1, idx2 = -2, dist = INT_MAX;
		for(int i = 0; i < words.size(); ++i) {
			if(word1 == word2) {
				if(words[i] == word1) {//two words are same
					if(idx1 > idx2) {idx2 = i;}//last time p1 updated
					else {idx1 = i;}//last time p2 updated
				}
			}else {
                                if(words[i] == word1) {idx1 = i;}
                                else if(words[i] = word2) {idx2 = i;}
			}
			if(idx1 != -1 && idx2 != -1) {//make sure that two words have already appeared at least once
				dist = min(dist, abs(idx1 - idx2));
			}
		}
		return dist;
	}
};
