class solution {
public:
	int maxArea(vector<int>& height) {
		if(height.size() < 2) {return 0;}

		int mxArea = 0;
		int left = 0;
		int right = height.size() - 1;
	
		while(left < right) {
			int curArea = (right - left) * min(height[left], height[right]);//shorter one decides the size
			mxArea = max(mxArea, curArea);
			if(height[left] < height[right]) {//move the smaller one
				++left;			
			}else if(height[left] > height[right]) {
				--right;
			}else {
				++left;
				--right;
			}
		}
		return mxArea;
	}
};
