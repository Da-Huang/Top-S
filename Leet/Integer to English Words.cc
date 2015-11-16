// #redo
string numberToWords(int num) {
  if (num == 0) return "Zero";
  static const char *SINGLE[20] = {
      "",        "One",     "Two",       "Three",    "Four",
      "Five",    "Six",     "Seven",     "Eight",    "Nine",
      "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  static const char *TEN[10] = {"",       "",      "Twenty", "Thirty",
                                "Forty",  "Fifty", "Sixty",  "Seventy",
                                "Eighty", "Ninety"};
  static const char *HUNDRED = "Hundred";
  static const char *THOUSAND[3] = {"Thousand", "Million", "Billion"};
  string ans;
  int base = 1;
  int i = 0;
  while (num / base / 1000) {
    ++i;
    base *= 1000;
  }
  while (i >= 0) {
    int p = num / base % 1000;
    if (p / 100) {
      ans += string(SINGLE[p / 100]) + " " + HUNDRED + " ";
    }
    int p0 = p % 100;
    if (p0 >= 20) {
      ans += string(TEN[p0 / 10]) + " ";
      p0 %= 10;
    }
    if (p0) {
      ans += string(SINGLE[p0]) + " ";
    }
    --i;
    if (p && i >= 0) {
      ans += string(THOUSAND[i]) + " ";
    }
    base /= 1000;
  }
  ans.pop_back();
  return ans;
}
