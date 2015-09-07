// #redo
string DeleteDigits(string A, int k) {
  while (k) {
    if (A.size() <= 1) return A;
    int j = 0;
    for (; j + 1 < (int)A.size(); ++j) {
      if (A[j] > A[j + 1]) break;
    }
    if (j + 1 == (int)A.size()) {
      A.resize((int)A.size() - k);
      break;
    }
    A.erase(j, 1);
    --k;
  }
  int i = 0;
  for (; i + 1 < (int)A.size(); ++i) {
    if (A[i] != '0') break;
  }
  A.erase(0, i);
  return A;
}
