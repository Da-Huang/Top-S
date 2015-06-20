bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p == NULL) return q == NULL;
  if (q == NULL) return p == NULL;
  return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
