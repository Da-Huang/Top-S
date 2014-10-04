// Redo
vector<int> findSubstring(string S, vector<string> &L) {
  vector<int> res;
  const int N = S.length();
  const int M = L.size();
  if ( N == 0 || M == 0 ) return res;
  const int W = L[0].length();

  unordered_map<string, int> dict;
  for (auto &s : L) dict[s] ++;
  unordered_map<string, int> mapping;
  int count = 0;
  for (int t = 0; t < W; t ++) {
    int begin = t;
    int end = t;
    while ( true ) {
      if ( end + W > N || dict.find(S.substr(end, W)) == dict.end() ) {
        while ( begin < end ) {
          mapping[S.substr(begin, W)] --;
          count --;
          begin += W;
        }
        begin += W;
        end += W;
        if ( end >= N ) break;

      } else if ( mapping[S.substr(end, W)] < dict[S.substr(end, W)] ) {
        mapping[S.substr(end, W)] ++;
        count ++;
        end += W;
        if ( count == M ) res.push_back(begin);

      } else {
        while ( S.substr(begin, W) != S.substr(end, W) ) {
          mapping[S.substr(begin, W)] --;
          count --;
          begin += W;
        }
        mapping[S.substr(begin, W)] --;
        count --;
        begin += W;
      }
    }
  }
  return res;
}

