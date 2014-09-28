int maxArea(vector<int> &height) {
  const int N = height.size();
  if ( N <= 1 ) return 0;
  auto it = max_element(height.begin(), height.end());
  int maxIndex = distance(height.begin(), it);
  vector<int> norm(N);
  norm[0] = height[0];
  for (int i = 1; i < maxIndex; i ++) 
    norm[i] = max(norm[i - 1], height[i]);
  norm[N - 1] = height[N - 1];
  for (int i = N - 2; i >= maxIndex; i --)
    norm[i] = max(norm[i + 1], height[i]);
  int res = 0;
  int left = maxIndex - 1, right = maxIndex + 1;
  while ( left >= 0 && right < N ) {
    if ( norm[left] > norm[right] ) {
      left --;
    } else {
      right ++;
    }
    int area = min(norm[left + 1], norm[right - 1]) * (right - left - 2);
    res = max(area, res);
  }
  while ( left >= 0 ) {
    left --;
    int area = min(norm[left + 1], norm[right - 1]) * (right - left - 2);
    res = max(area, res);
  }
  while ( right < N ) {
    right ++;
    int area = min(norm[left + 1], norm[right - 1]) * (right - left - 2);
    res = max(area, res);
  }
  return res;
}

