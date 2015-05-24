void flatten(TreeNode* root) {
  while (root) {
    TreeNode *l = root->left;
    if (l) {
      TreeNode *ltail = l;
      while (ltail->right) ltail = ltail->right;
      ltail->right = root->right;
      root->right = l;
      root->left = NULL;
    }
    root = root->right;
  }
}
