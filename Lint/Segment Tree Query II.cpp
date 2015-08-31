// #redo
int query(SegmentTreeNode *root, int start, int end) {
  if (root == nullptr) return 0;
  if (start > root->end || end < root->start) return 0;
  if (start <= root->start && root->end <= end) return root->count;
  return query(root->left, start, end) + query(root->right, start, end);
}
