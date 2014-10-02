int maxProfit(vector<int> &prices) {
  const int N = prices.size();
  int res = 0;
  int begin = 0;
  while ( begin < N ) {
    int end = begin + 1;
    while ( end < N && prices[end] >= prices[end - 1] ) end ++;
    res += prices[end - 1] - prices[begin];
    begin = end;
  }
  return res;
}

