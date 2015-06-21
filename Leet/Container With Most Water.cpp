// #redo
int maxArea(vector<int>& height) {
  int ans = 0;
  int i = 0, j = (int) height.size() - 1;
  while (i < j) {
    if (height[i] <= height[j]) {
      ans = max(ans, height[i] * (j - i));
      i ++;

    } else {
      ans = max(ans, height[j] * (j - i));
      j --;
    }
  }
  return ans;
}
