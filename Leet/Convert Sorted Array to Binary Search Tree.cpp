TreeNode *__cons(vector<int> &num, int first, int last) {
  if ( first > last ) return NULL;
  int mid = (first + last) / 2;
  TreeNode *root = new TreeNode(num[mid]);
  root->left = __cons(num, first, mid - 1);
  root->right = __cons(num, mid + 1, last);
  return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
  return __cons(num, 0, (int) num.size() - 1);
}

