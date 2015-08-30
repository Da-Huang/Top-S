// #redo
TreeNode *__sortedArrayToBST(vector<int> &A, int first, int last) {
  if (first > last) return nullptr;
  int mid = first + (last - first) / 2;
  TreeNode *root = new TreeNode(A[mid]);
  root->left = __sortedArrayToBST(A, first, mid - 1);
  root->right = __sortedArrayToBST(A, mid + 1, last);
  return root;
}

TreeNode *sortedArrayToBST(vector<int> &A) {
  return __sortedArrayToBST(A, 0, (int)A.size() - 1);
}
