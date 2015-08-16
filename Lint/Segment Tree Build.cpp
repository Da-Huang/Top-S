// #redo
SegmentTreeNode * build(int start, int end) {
  if (start > end) return nullptr;
  SegmentTreeNode *root = new SegmentTreeNode(start, end);
  if (start == end) return root;
  root->left = build(start, start + (end - start) / 2);
  root->right = build(start + (end - start) / 2 + 1, end);
  return root;
}
