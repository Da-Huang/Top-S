// #redo
string intToRoman(int num) {
  string ans;
  char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  int i = 0;
  while (num) {
    int p = num % 10;
    if (p == 9) {
      ans.push_back(roman[i + 2]);
      ans.push_back(roman[i]);
    } else if (p == 4) {
      ans.push_back(roman[i + 1]);
      ans.push_back(roman[i]);
    } else if (p >= 5) {
      ans.insert(ans.end(), p - 5, roman[i]);
      ans.push_back(roman[i + 1]);
    } else {
      ans.insert(ans.end(), p, roman[i]);
    }
    num /= 10;
    i += 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
