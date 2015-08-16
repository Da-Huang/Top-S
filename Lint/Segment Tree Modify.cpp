// #redo
void modify(SegmentTreeNode *root, int index, int value) {
  if (root->start == root->end) {
    root->max = value;
    return;
  }
  
  if (index <= root->left->end) modify(root->left, index, value);
  else modify(root->right, index, value);
  root->max = max(root->left->max, root->right->max);
}
