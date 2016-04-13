class solution {
public:
	int numDecoding(string s) {
		if(s.empty() || s[0] < '1' || s[0] > '9') {return 0;}
		vector<int> dp(s.size() + 1, 0);//dp[i + 1] -> s(0:i)
		dp[0] = dp[1] = 1;
		
		for(int i = 1; i < s.size(); ++i) {
			int val = s[i - 1] * 10 + s[i];
			if(val <= 26 && val > 9) {//if the number is between 10-26, then it can be decoded as a char
				dp[i + 1] += dp[i - 1];
			}
			if(s[i] != '0') {//if this number is 0, then it can only be treated as a xx not x
				dp[i + 1] += dp[i];
			}
		}
		return dp.back();
	}
};
