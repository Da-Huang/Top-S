int __sumNumbers(TreeNode *root, int base) {
  if (root == NULL) return 0;
  base = base * 10 + root->val;
  if (root->left == NULL && root->right == NULL) return base;
  int ans = 0;
  if (root->left) ans += __sumNumbers(root->left, base);
  if (root->right) ans += __sumNumbers(root->right, base);
  return ans;
}

int sumNumbers(TreeNode* root) {
  return __sumNumbers(root, 0);
}
