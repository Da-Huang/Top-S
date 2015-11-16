void __letterCombinations(string phone[], string &digits, size_t begin, string &v, vector<string> &ans) {
  if (begin == digits.size()) {
    ans.push_back(v);
    return;
  }
  for (char c : phone[digits[begin]-'0']) {
    v.push_back(c);
    __letterCombinations(phone, digits, begin+1, v, ans);
    v.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  static string phone[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  string v;
  vector<string> ans;
  if (digits.empty()) return ans;
  __letterCombinations(phone, digits, 0, v, ans);
  return ans;
}
