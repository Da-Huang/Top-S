// Redo
int sqrt(int x) {
  if ( x == 0 ) return 0;
  int last = x;
  int first = 1;
  while ( first < last ) {
    const int mid = first + (last - first) / 2;
    if ( mid > x / mid ) last = mid - 1;
    else if ( mid < x / mid ) first = mid + 1;
    else return mid;
  }
  if ( first > x / first ) return first - 1;
  else return first;
}

