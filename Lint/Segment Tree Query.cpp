// #redo
int query(SegmentTreeNode *root, int start, int end) {
  if (start <= root->start && root->end <= end) return root->max;
  if (end <= root->left->end) return query(root->left, start, end);
  if (root->right->start <= start) return query(root->right, start, end);
  return max(query(root->left, start, end), query(root->right, start, end));
}
