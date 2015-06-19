int countNodes(TreeNode* root) {
  int ans = 0;
  while (root) {
    int cl = 0, cr = 0;
    for (TreeNode *ptr = root; ptr; ptr = ptr->left) ++ cl;
    for (TreeNode *ptr = root; ptr; ptr = ptr->right) ++ cr;
    if (cl == cr) {
      ans += (1 << cl) - 1;
      break;
    } else {
      int crl = 0;
      for (TreeNode *ptr = root->right; ptr; ptr = ptr->left) ++ crl;
      if (crl == cr - 1) {
        ans += 1 << crl;
        root = root->left;
      } else {
        ans += 1 << (cl - 1);
        root = root->right;
      }
    }
  }
  return ans;
}
