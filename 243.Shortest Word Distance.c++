class solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int idx1 = -1, idx2 = -1, dist = INT_MAX;
		for(int i = 0; i < words.size(); ++i) {
			if(words[i] == word1) {
				idx1 = i;
			}else if(word[i] == word2) {
				idx2 = i;
			}
			if(idx1 != -1 && idx2 != -1) {//make sure that two words have already appeared at least once
				dist = min(dist, abs(idx1 - idx2));
			}
		}
		return dist;
	}
};
