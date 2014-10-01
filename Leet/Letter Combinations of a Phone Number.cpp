vector<string> letterCombinations(const string &digits, const string dict[], int start=0) {
  const int N = digits.size();
  vector<string> res;
  if ( start == N ) {
    res.push_back("");
    return res;
  }
  vector<string> subRes = letterCombinations(digits, dict, start + 1);

  const string &mapping = dict[digits[start] - '0'];
  if ( mapping.length() == 0 ) return subRes;

  for (auto &item : subRes) {
    item.insert(item.begin(), '?');
  }
  for (auto &c : mapping) {
    for (auto &item : subRes) {
      item[0] = c;
      res.push_back(item);
    }
  }
  return res;
}

vector<string> letterCombinations(string digits) {
  static const string dict[10] = {"", "", "abc", "edf", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  return letterCombinations(digits, dict);
}
