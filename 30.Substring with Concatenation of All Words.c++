class solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> allPos;
		if(s.empty() || words.empty()) {
			return allPos;
		}
		//get information fo words
		int numWords = words.size();
		int lenWords = words[0].size();
		int length = numWords * lenWords;

		if(s.size() < length) {
			return allPos;
		}

		unordered_map<string, int> countWords;

		for(auto a : words) {
			++countWords[a];
		}

		for(int i = 0; i <= s.size() - length; ++i) {
			if(check(s,i,countWords,numWords,lenWords) {
				allPos.push_back(i);
			}
		}

		return allPos;
	}
private:
	bool check(string s, int start, unordered_map<string, int> countWords, int numWords, int lenWords) {
		unordered_map<string, int> foundWords;

		for(int i = 0; i < numWords; ++i) {
			string temp = s.substr(start + i * lenWords, lenWords);
			if(!countWords.count(temp)) {
				return false;
			}
			++foundWords[temp];
			if(foundWords[temp] > countWords[temp]) {
				return false;		
			}
		}
		return true;
	}
};
