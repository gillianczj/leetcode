class solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() < 2) {return 0;}
		int n = prices.size();

		//from left to right
		int leftMinVal = prices[0];//left min value
		int leftMaxPro = 0;//left max profit
		vector<int> left(n, 0);//container of profit

		for(int i = 1; i < n; ++i) {
			if(prices[i] < leftMinVal) {
				leftMinVal = prices[i];
			}else {
				leftMaxPro = max(leftMaxPro, prices[i] - leftMinVal);
			}
			left[i] = leftMaxPro;
		}

		//from right to left
		int rightMaxVal = prices.back();//right max vlaue
		int rightMaxPro = 0;//right max profit
		int ret = 0;//return value
		
		for(int i = n - 2; i >= 0; --i) {
			if(prices[i] > rightMaxVal) {
				rightMaxVal = prices[i];
			}else {
				rightMaxPro = max(rightMaxPro, rightMaxVal - prices[i]);
			}
			ret = max(ret, left[i] + rightMaxPro);
		}

		return ret;
	}
};
