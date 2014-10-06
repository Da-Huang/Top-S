TreeNode *__build(vector<int> &preorder, vector<int> &inorder, int preFirst, int inFirst, int n) {
  if ( n == 0 ) return NULL;
  TreeNode *root = new TreeNode(preorder[preFirst]);
  int i;
  for (i = inFirst; i < inFirst + n; i ++) {
    if ( inorder[i] == root->val ) break;
  }
  root->left = __build(preorder, inorder, preFirst + 1, inFirst, i - inFirst);
  root->right = __build(preorder, inorder, preFirst + 1 + i - inFirst, i + 1, n - 1 - i + inFirst);
  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  const int N = preorder.size();
  return __build(preorder, inorder, 0, 0, N);
}

