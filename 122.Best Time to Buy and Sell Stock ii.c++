class solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() < 2) {
			return 0;
		}
		int ret = 0;
		for(int i = 1; i < prices.size(); ++i) {
			ret += (prices[i] > prices[i - 1]) ? (prices[i] - prices[i - 1]) : 0;//add every increase
		}

		return ret;
	}
};
