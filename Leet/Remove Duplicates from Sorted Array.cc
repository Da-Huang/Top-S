int removeDuplicates(int A[], int n) {
  int begin = 0, end = 0;
  while ( end < n ) {
    A[begin] = A[end];
    end ++;
    while ( end < n && A[begin] == A[end] ) end ++;
    begin ++;
  }
  return begin;
}


// #version2
int removeDuplicates(vector<int>& nums) {
  int k = 0;
  for (size_t i = 0; i < nums.size(); ++ i) {
    if (i == 0 || nums[i] != nums[i - 1]) nums[k ++] = nums[i];
  }
  return k;
}
