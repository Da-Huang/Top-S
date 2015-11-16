// #redo
bool firstWillWin(vector<int> &values) {
  const int N = values.size();
  int win_values[2] = {0, 0};
  for (int i = N-1; i >= 0; --i) {
    if (i >= N-1) win_values[i&1] = values[i];
    else win_values[i&1] = max(values[i] - win_values[(i+1)&1], values[i] + values[i+1] - win_values[i&1]);
  }
  return win_values[0] > 0;
}
