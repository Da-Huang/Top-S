int __sumNumbers(TreeNode *root, int mul) {
  if ( root->left == NULL && root->right == NULL ) {
    return mul * 10 + root->val;
  }
  int res = 0;
  if ( root->left ) {
    res += __sumNumbers(root->left, mul * 10 + root->val);
  }
  if ( root->right ) {
    res += __sumNumbers(root->right, mul * 10 + root->val);
  }
  return res;
}

int sumNumbers(TreeNode *root) {
  if ( root == NULL ) return 0;
  return __sumNumbers(root, 0);
}
