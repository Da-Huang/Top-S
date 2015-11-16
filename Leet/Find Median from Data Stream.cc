class MedianFinder {
 public:
  // Adds a number into the data structure.
  void addNum(int num) {
    if (smaller.empty())
      smaller.push_back(num);
    else if (smaller.front() >= num) {
      smaller.push_back(num);
      push_heap(smaller.begin(), smaller.end());
      if (smaller.size() > bigger.size() + 1) {
        bigger.push_back(smaller.front());
        push_heap(bigger.begin(), bigger.end(), greater<int>());
        pop_heap(smaller.begin(), smaller.end());
        smaller.pop_back();
      }
    } else {
      bigger.push_back(num);
      push_heap(bigger.begin(), bigger.end(), greater<int>());
      if (bigger.size() > smaller.size()) {
        smaller.push_back(bigger.front());
        push_heap(smaller.begin(), smaller.end());
        pop_heap(bigger.begin(), bigger.end(), greater<int>());
        bigger.pop_back();
      }
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    if (bigger.size() == smaller.size()) {
      return bigger.empty() ? 0
                            : ((double)bigger.front() + smaller.front()) / 2;
    }
    return smaller.front();
  }

 private:
  vector<int> smaller;  // maxheap
  vector<int> bigger;   // minheap
};
