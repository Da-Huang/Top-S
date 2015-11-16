class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < (int)matrix.size(); ++i) {
      sums_.push_back(vector<int>());
      int sum = 0;
      for (int j = 0; j < (int)matrix[0].size(); ++j) {
        sums_.back().push_back((sum += matrix[i][j]) +
                               (i ? sums_[i - 1][j] : 0));
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sums_[row2][col2] - (row1 ? sums_[row1 - 1][col2] : 0) -
           (col1 ? sums_[row2][col1 - 1] : 0) +
           (row1 && col1 ? sums_[row1 - 1][col1 - 1] : 0);
  }

 private:
  vector<vector<int>> sums_;
};
