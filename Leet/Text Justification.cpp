vector<string> fullJustify(vector<string> &words, int L) {
  const int N = words.size();
  vector<string> res;
  int begin = 0;
  while ( begin < N ) {
    int width = words[begin].length();
    int end = begin + 1;
    while ( end < N && width + words[end].length() + 1 <= L ) {
      width += words[end].length() + 1;
      end ++;
    }
    if ( end == N ) {
      // This is the last line
      string line = words[begin];
      for (int i = begin + 1; i < end; i ++) {
        line += " ";
        line += words[i];
      }
      line.resize(L, ' ');
      res.push_back(line);
      return res;
    }

    if ( end == begin + 1 ) {
      string line = words[begin];
      line.resize(L, ' ');
      res.push_back(line);

    } else {
      int remainSpaces = L - width;
      int lessSpaces = remainSpaces / (end - begin - 1);
      int moreSpacesCount = remainSpaces % (end - begin - 1);
      string line = words[begin];
      int i = begin + 1;
      while ( i <= begin + moreSpacesCount ) {
        line.insert(line.end(), 2 + lessSpaces, ' ');
        line += words[i];
        i ++;
      }
      while ( i < end ) {
        line.insert(line.end(), 1 + lessSpaces, ' ');
        line += words[i];
        i ++;
      }
      res.push_back(line);
    }
    begin = end;
  }
  return res;
}

