class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {}

    void addNum(int num) {
        if (maxheap.empty()) {
            maxheap.push(num);
        } else {
            if (maxheap.top() < num) {
                minheap.push(num);
            } else {
                maxheap.push(num);
            }
            while (maxheap.size() > minheap.size() + 1) {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            while (maxheap.size() < minheap.size()) {
                maxheap.push(minheap.top());
                minheap.pop();
            }
            
        }
    }

    double findMedian() {
        if (maxheap.size() == minheap.size()) {
            return (double)(minheap.top() + maxheap.top()) / 2.0;
        } else {
            return (double)maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */