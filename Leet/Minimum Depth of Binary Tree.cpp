int minDepth(TreeNode *root) {
  if ( root == NULL ) return 0;
  if ( root->left == NULL && root->right == NULL ) return 1;
  int res = INT_MAX;
  if ( root->left ) {
    res = min(res, minDepth(root->left));
  }
  if ( root->right ) {
    res = min(res, minDepth(root->right));
  }
  return res + 1;
}

