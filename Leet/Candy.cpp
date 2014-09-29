int candy(vector<int> &ratings) {
  const int N = ratings.size();
  if ( N == 0 ) return 0;
  int res = 0;
  int begin = 0;
  int startBefore = 0;
  while ( begin < N ) {
    int end = begin + 1;
    while ( end < N && ratings[end] > ratings[end - 1] ) end ++;
    int incTop = end - begin + startBefore;
    begin = end - 1;
    while ( end < N && ratings[end] < ratings[end - 1] ) end ++;
    int decTop = end - begin;
    res += incTop * (incTop - 1) / 2 + decTop * (decTop - 1) / 2 - startBefore;
    res += max(incTop, decTop);
    begin = end;

    if ( begin < N && ratings[begin] == ratings[begin - 1] ) startBefore = 0;
    else startBefore = 1;

    if ( end >= N ) break;
  }
  return res;
}

