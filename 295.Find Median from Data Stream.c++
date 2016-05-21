struct comp {
    bool operator()(int num1, int num2) {
        return num1 > num2;
    }
};

class MedianFinder {
public:
    //adds a number into the data structure
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) {//belong to maxHeap
            if(maxHeap.size() > minHeap.size()) {//rebalance
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            maxHeap.push(num);
        }else if(minHeap.empty() || num > minHeap.top()) {//belong to minHeap
            if(minHeap.size() > maxHeap.size()) {//rebalance
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            minHeap.push(num);
        }else {//in between
            if(maxHeap.size() <= minHeap.size()) {//go to the smaller one
                maxHeap.push(num);
            }else {
                minHeap.push(num);
            }
        }
    }

    //returns the median of current data stream
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (double) (minHeap.top() + maxHeap.top()) / 2;
        }else {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
private:
    priority_queue<int, vector<int>, comp> minHeap;
    priority_queue<int, vector<int>> maxHeap;//default maxHeap
};
