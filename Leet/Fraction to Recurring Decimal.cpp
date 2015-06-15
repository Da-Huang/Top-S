// #redo
string fractionToDecimal(int numerator, int denominator) {
  if (denominator == 0) return "NAN";
  if (numerator == 0) return "0";
  if (denominator == -1 && numerator == INT_MIN) return to_string(INT_MIN).substr(1);

  string ans = to_string(numerator / denominator);
  if (ans.front() == '0') {
    if ((numerator < 0) ^ (denominator < 0)) ans = "-" + ans;
  }

  numerator %= denominator;
  if (numerator == 0) return ans;
  ans += ".";

  if (numerator > 0) numerator = -numerator;
  if (denominator > 0) denominator = -denominator;

  unordered_map<int, size_t> MAP;
  while (numerator) {
    MAP[numerator] = ans.size();
    int p, q;
    if (denominator > -100) {
      p = numerator * 10 / denominator;
      q = numerator * 10 % denominator;

    } else {
      int dx = denominator / 10;
      int dy = denominator % 10;
      int alpha = numerator / dx;
      int beta  = numerator % dx;
      q = 10 * beta - alpha * dy;
      if (q <= 0) p = alpha;
      else {
        p = alpha - 1;
        q += denominator;
      }
    }
    ans.push_back(p + '0');

    auto it = MAP.find(q);
    if (it != MAP.end()) {
      ans.insert(it->second, "(");
      ans += ")";
      break;
    } else {
      numerator = q;
    }
  }
  return ans;
}
