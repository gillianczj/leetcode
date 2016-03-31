class solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() < 2) {return 0}
		int minVal = prices[0];
		int maxPro = 0;
		//find the max gap
		for(int i = 1; i < prices.size(); ++i) {
			if(prices[i] < minVal) {
				minVal = prices[i];
			}else {
				maxPro = max(maxPro, prices[i] - minVal);
			}
		}

		return maxPro;
	}
};
