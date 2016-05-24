class solution {
public:
    int mySqrt(int x) {
        if(x <= 1) {
            return x;
        }

        int start = 0;
        int end = x;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(x / mid == mid) {
                return mid;
            }else if(x / mid > mid) {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }

        return end;//the less one
    }
};
