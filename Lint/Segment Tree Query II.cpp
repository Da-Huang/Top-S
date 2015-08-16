// #redo
int query(SegmentTreeNode *root, int start, int end) {
  if (root == nullptr || end < root->start || start > root->end) return 0;
  if (start <= root->start && root->end <= end) return root->count;
  if (end <= root->left->end) return query(root->left, start, end);
  if (root->right->start <= start) return query(root->right, start, end);
  return query(root->left, start, end) + query(root->right, start, end);
}
