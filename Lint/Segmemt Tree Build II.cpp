// #redo
SegmentTreeNode *__build(vector<int> &A, int start, int end) {
  if (start > end) return nullptr;
  if (start == end) return new SegmentTreeNode(start, end, A[start]);

  int mid = start + (end - start) / 2;
  SegmentTreeNode *left = __build(A, start, mid);
  SegmentTreeNode *right = __build(A, mid + 1, end);
  SegmentTreeNode *root =
      new SegmentTreeNode(start, end, max(left->max, right->max));
  root->left = left;
  root->right = right;
  return root;
}

SegmentTreeNode *build(vector<int> &A) {
  return __build(A, 0, (int)A.size() - 1);
}
