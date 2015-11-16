class NumArray {
 public:
  NumArray(vector<int> &nums) {
    int sum = 0;
    for (int num : nums) {
      sums_.push_back(sum += num);
    }
  }

  int sumRange(int i, int j) { return i ? sums_[j] - sums_[i - 1] : sums_[j]; }

 private:
  vector<int> sums_;
};
