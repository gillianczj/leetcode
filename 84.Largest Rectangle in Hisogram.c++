class solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(INT_MIN);//make sure the shortest would be counted
		int maxArea = 0;
		stack<int> s;
		for(int i = 0; i < heights.size();) {
			if(s.empty() || heights[i] >= heights[s.top()]) {s.push(i++);}//increasing then push
			else {
				int cur = s.top();//current index
				s.pop();
				int width = s.empty() ? i : i - s.top() - 1;//calculate the width
				maxArea = max(maxArea, width * heights[cur]);//update the max area
			}
		}
		return maxArea;
	}
};
