// #redo
void rerange(vector<int> &A) {
  int negative_count = 0;
  for (int num : A)
    if (num < 0) ++negative_count;
  bool first_negative = negative_count >= ((int)A.size() - negative_count);

  size_t i = 0, j = 1;
  while (j < A.size()) {
    if (i & 1) {
      if ((A[i] < 0) ^ first_negative) {
        ++i;
        if (j <= i) ++j;
      } else if ((A[j] < 0) ^ first_negative) {
        swap(A[i], A[j]);
        ++i;
        ++j;
      } else {
        ++j;
      }
    } else {
      if ((A[i] >= 0) ^ first_negative) {
        ++i;
        if (j <= i) ++j;
      } else if ((A[j] >= 0) ^ first_negative) {
        swap(A[i], A[j]);
        ++i;
        ++j;
      } else {
        ++j;
      }
    }
  }
}
