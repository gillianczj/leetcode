class wordDistance {
public:
	wordDistance(vector<int>& words) {
		for(int i = 0; i < words.size(); ++i) {
			mp[words[i]].push_back(i);
		}
	}

	int shortest(string word1, string word2) {
		vector<int> idx1 = mp[word1];//idxs of word1
		vector<int> idx2 = mp[word2];//idxs of word2
		int i = 0, j = 0, dist = INT_MAX;
		while(i < idx1.size() && j < idx2.size()) {
			dist = min(dist, abs(idx1[i] - idx2[j]));//update min distance
			if(idx1[i] < idx2[j]) {++i;}//to shorten the distance
			else {++j;}
		}
		return dist;
	}
private:
	unordered_map<string, vector<int>> mp;//store idxs of each word, idxs are sortex
};
