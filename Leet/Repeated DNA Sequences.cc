// #redo
vector<string> findRepeatedDnaSequences(string s) {
  const int N = s.size();
  const int M = 10;
  const int MASK = (1 << 20) - 1;
  char DNA[26];
  DNA['A' - 'A'] = 0;
  DNA['C' - 'A'] = 1;
  DNA['G' - 'A'] = 2;
  DNA['T' - 'A'] = 3;

  vector<string> ans;
  unordered_map<int, int> MAP;
  int val = 0;
  for (int i = 0; i < N; ++ i) {
    val = ((val << 2) & MASK) | DNA[s[i] - 'A'];
    if (i >= M - 1) {
      if (++ MAP[val] == 2)
        ans.push_back(s.substr(i+1-M, M));
    }
  }
  return ans;
}
