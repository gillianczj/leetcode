//stack solution
class solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if(n < 3) {return 0;}//at least three bars to make a container
		stack<int> s;
		int water = 0;
		for(int i = 0; i < n; ++i) {
			if(!s.empty() && height[i] > height[s.top()]) {//increase
				int bottom = height[s.top()];
				s.pop();
				while(!s.empty() && height[i] >= height[s.top()]) {//height is decided by height[s.top()] and is gonna continue poping
					water += (height[s.top()] - bottom) * (i - s.top() - 1);//update water
					bottom = height[s.top()];//update bottom
					s.pop();
				}
				if(!s.empty()) {//height is decided by height[i]
					water += (height[i] - bottom) * (i - s.top() - 1);
				} 
			}
			s.push(i);//height[i] becomes the new bottom
		}
		return water;
	}
};

//two pointers solution
class solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if(n < 3) {return 0;}
		vector<int> leftMax(n, 0);
		vector<int> rightMax(n, 0);
		int water = 0;
		for(int i = 1; i < n - 1; ++i) {//find left max height
			leftMax[i] = max(leftMax[i - 1], height[i - 1]);
		}
		for(int i = n - 2; i > 0; --i) {//find right max height and update water
			rightMax[i] = max(rightMax[i + 1], height[i + 1]);
			int h = min(leftMax[i], rightMax[i]);
			water += h > height[i] ? (h - height[i]) : 0;
		}//the first and last index do not need to be considered
		return water;
	}
};
