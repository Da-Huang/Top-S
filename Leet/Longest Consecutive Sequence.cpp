int longestConsecutive(vector<int> &num) {
  unordered_set<int> SET;
  SET.insert(num.begin(), num.end());
  int res = 0;
  for (auto i : num) {
    if ( SET.find(i) == SET.end() ) continue;
    int j = i - 1;
    while ( SET.find(j) != SET.end() ) {
      SET.erase(j);
      j --;
    }
    int k = i + 1;
    while ( SET.find(k) != SET.end() ) {
      SET.erase(k);
      k ++;
    }
    SET.erase(i);
    res = max(res, k - j - 1);
  }
  return res;
}

