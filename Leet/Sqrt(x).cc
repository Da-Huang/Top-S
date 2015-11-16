// #redo
int mySqrt(int x) {
  if (x <= 1) return x;
  int first = 1, last = x;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (mid > x / mid) last = mid;
    else if (mid < x / mid) first = mid + 1;
    else return mid;
  }
  return first - 1;
}
