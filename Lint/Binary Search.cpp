int binarySearch(vector<int> &array, int target) {
  int first = 0, last = (int)array.size();
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (array[mid] < target)
      first = mid + 1;
    else
      last = mid;
  }
  return first < (int)array.size() && array[first] == target ? first : -1;
}
