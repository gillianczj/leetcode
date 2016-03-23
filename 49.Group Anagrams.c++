class solution {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		unordered_map<string, multiset<string>> mp;
		//classify
		for(auto a : strs) {
			string t = a;
			sort(t.begin(), t.end());
			mp[t].insert(a);
		}

		vector<vector<string>> ret;

		for(auto m : mp) {
			//sort
			vector<string> temp(m.second.begin(),m.second.end());
			ret.push_back(temp);
		}

		return ret;
	}
};
