// Dangerous
TreeNode *__build(vector<int> &inorder, vector<int> &postorder, int inFirst, int postFirst, int n) {
  if ( n == 0 ) return NULL;
  TreeNode *root = new TreeNode(postorder[postFirst + n - 1]);
  int i;
  for (i = inFirst; i < inFirst + n; i ++) {
    if ( inorder[i] == root->val ) break;
  }
  root->left = __build(inorder, postorder, inFirst, postFirst, i - inFirst);
  root->right = __build(inorder, postorder, i + 1, postFirst + i - inFirst, n - i + inFirst - 1);
  return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  const int N = inorder.size();
  return __build(inorder, postorder, 0, 0, N);
}

