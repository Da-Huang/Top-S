TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  while (root) {
    if (p->val == root->val || q->val == root->val) return root;
    if (p->val < root->val ^ q->val < root->val) return root;
    if (p->val < root->val) root = root->left;
    else root = root->right;
  }
  return nullptr;
}
