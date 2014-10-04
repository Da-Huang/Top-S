// Redo
string intToRoman(int num) {
  static char ROMAN[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  string res;
  int i = 6;
  int base = 1000;
  while ( base ) {
    int d = num / base % 10;
    if ( d <= 3 ) res.insert(res.end(), d, ROMAN[i]);
    else if ( d == 4 ) {
      res.push_back(ROMAN[i]);
      res.push_back(ROMAN[i + 1]);
    } else if ( d <= 8 ) {
      res.push_back(ROMAN[i + 1]);
      res.insert(res.end(), d - 5, ROMAN[i]);
    } else { // d == 9
      res.push_back(ROMAN[i]);
      res.push_back(ROMAN[i + 2]);
    }
    base /= 10;
    i -= 2;
  }
  return res;
}

