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


// #redo
// #version2
vector<string> anagrams(vector<string>& strs) {
  unordered_map<string, vector<size_t>> MAP;
  for (size_t i = 0; i < strs.size(); ++ i) {
    string str = strs[i];
    sort(str.begin(), str.end());
    MAP[str].push_back(i);
  }
  vector<string> ans;
  for (auto &p : MAP) {
    if (p.second.size() > 1) {
      for (size_t i : p.second) {
        ans.push_back(strs[i]);
      }
    }
  }
  return ans;
}
