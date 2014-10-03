// Solution 1
vector<int> twoSum(vector<int> &numbers, int target) {
  const int N = numbers.size();
  int indexes[N];
  for (int i = 0; i < N; i ++) indexes[i] = i;
  sort(indexes, indexes + N, [&numbers] (int i, int j) {
      return numbers[i] < numbers[j];
      });
  vector<int> res;
  int first = 0, last = N - 1;
  while ( first < last ) {
    if ( numbers[indexes[first]] + numbers[indexes[last]] > target ) last --;
    else if ( numbers[indexes[first]] + numbers[indexes[last]] < target ) first ++;
    else { // ==
      res.push_back(min(indexes[first], indexes[last]) + 1);
      res.push_back(max(indexes[first], indexes[last]) + 1);
      return res;
    }
  }
  return res;
}

// Solution 2
vector<int> twoSum(vector<int> &numbers, int target) {
  const int N = numbers.size();
  unordered_multimap<int, int> mapping;
  for (int i = 0; i < N; i ++) mapping.insert(make_pair(numbers[i], i));
  vector<int> res;
  for (int i = 0; i < N; i ++) {
    auto range = mapping.equal_range(target - numbers[i]);
    auto begin = range.first;
    auto end = range.second;
    for (auto p = begin; p != end; p ++) {
      if ( p->second != i ) {
        res.push_back(min(i, p->second) + 1);
        res.push_back(max(i, p->second) + 1);
      }
    }
  }
  return res;
}

