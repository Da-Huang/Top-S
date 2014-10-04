vector<string> anagrams(vector<string> &strs) {
  const int N = strs.size();
  unordered_map<string, int> mapping;
  for (int i = 0; i < N; i ++) {
    string item = strs[i];
    sort(item.begin(), item.end());
    mapping[item] ++;
  }
  vector<string> res;
  for (int i = 0; i < N; i ++) {
    string item = strs[i];
    sort(item.begin(), item.end());
    if ( mapping[item] > 1 ) res.push_back(strs[i]);
  }
  return res;
}

