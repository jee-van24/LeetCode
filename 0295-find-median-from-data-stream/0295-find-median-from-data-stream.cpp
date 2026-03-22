class MedianFinder {
public:
    vector<int> arr;

    MedianFinder() {}

    void addNum(int num) {
        int idx = -1;
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        arr.insert(arr.begin() + low, num);
    }

    double findMedian() {
        if ((arr.size() & 1) == 0) {
            // even
            int n = arr.size();
            double med = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
            return med;
        } else {
            return (double)arr[(arr.size()) / 2];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */