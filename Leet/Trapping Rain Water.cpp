int trap(vector<int>& height) {
  int ans = 0;
  int rh = 0, lh = 0;
  int i = 0, j = (int) height.size() - 1;
  while (i < j) {
    if (height[i] <= height[j]) {
      lh = max(lh, height[i]);
      ans += lh - height[i ++];

    } else {
      rh = max(rh, height[j]);
      ans += rh - height[j --];
    }
  }
  return ans;
}
