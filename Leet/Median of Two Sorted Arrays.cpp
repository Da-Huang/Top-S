// #redo
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  const int M = nums1.size();
  const int N = nums2.size();
  if (M == 0 && N == 0) return NAN;
  int i = 0, j = 0, k = (M + N - 1) / 2;
  int T = (M + N) & 1 ? 1 : 2;
  int ans = 0;
  for (int t = 0; t < T; ++ t) {
    while (k && i < M && j < N) {
      int k1 = min(i+(k-1)/2, M-1);
      int k2 = min(j+(k-1)/2, N-1);
      if (nums1[k1] >= nums2[k2]) {
        k -= k2 + 1 - j;
        j = k2 + 1;
      } else {
        k -= k1 + 1 - i;
        i = k1 + 1;
      }
    }
    if (i == M) {
      ans += nums2[j+k];
      j += k + 1;
      k = 0;
    } else if (j == N) {
      ans += nums1[i+k];
      i += k + 1;
      k = 0;
    } else if (nums1[i] >= nums2[j]) { // k == 0
      ans += nums2[j];
      ++ j;
    } else {
      ans += nums1[i];
      ++ i;
    }
  }
  return (double) ans / T;
}
