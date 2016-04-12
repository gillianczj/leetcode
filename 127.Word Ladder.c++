class solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		wordList.insert(endWord);//put endWord in the dict
		queue<pair<string, int>> q;//for BFS, pair stores current string and length
		q.push(make_pair(beginWord, 1));
		while(!q.empty()) {
			string s = q.front().first;
			int len = q.front().second;
			q.pop();
			if(s == endWord) {
				return len;
			}else {
				vector<string> neighbors = findNeighbors(s, wordList);//find all neighbors and push them to string
				for(auto a : neighbors) {
					q.push(make_pair(a, len + 1));
				}
			}
		}
		return 0;
	}
private:
	vector<string> findNeighbors(string& s, unordered_set<string>& wordList) {
		vector<string> ret;
		for(int i = 0; i < s.size(); ++i) {//change every char in s to other 25 chars to see if there is a match in wordList
			char c = s[i];
			for(int j = 0; j < 26; ++j) {
				if(c == 'a' + j) {continue;}
	                        else {
        	                        s[i] = 'a' + j;
                	                if(wordList.count(s)) {//find a match then put it in return array and erase it from wordList
                        	                ret.push_back(s);
                                	        wordList.erase(s);
                               		 }	
                       		 }
			}
			s[i] = c;//reset s
		}
		return ret;
	}
}:
