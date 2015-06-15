void recoverTree(TreeNode* root) {
  TreeNode *last = NULL, *p = NULL, *q;
  while (root) {
    TreeNode *lr = root->left;
    if (lr) {
      while (lr->right && lr->right != root) lr = lr->right;
      if (lr->right == NULL) {
        lr->right = root;
        root = root->left;
        continue;
      }
      lr->right = NULL;
    }
    if (last && last->val > root->val) {
      if (p == NULL) {
        p = last;
        q = root;
      } else {
        q = root;
      }
    }
    last = root;
    root = root->right;
  }
  swap(p->val, q->val);
}
