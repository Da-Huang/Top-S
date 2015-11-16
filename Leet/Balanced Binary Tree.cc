int __isBalance(TreeNode *root) {
  if (root == NULL) return 0;
  int ansl = __isBalance(root->left);
  if (ansl < 0) return -1;
  int ansr = __isBalance(root->right);
  if (ansr < 0) return -1;
  if (abs(ansl - ansr) > 1) return -1;
  return max(ansl, ansr) + 1;
}

bool isBalanced(TreeNode* root) {
  return __isBalance(root) >= 0;
}
