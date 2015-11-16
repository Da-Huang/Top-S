bool __isSymmetrix(TreeNode *t1, TreeNode *t2) {
  if (t1 == NULL && t2 == NULL) return true;
  if (t1 && t2) return t1->val == t2->val && __isSymmetrix(t1->left, t2->right) && __isSymmetrix(t1->right, t2->left);
  return false;
}

bool isSymmetric(TreeNode* root) {
  if (root == NULL) return true;
  return __isSymmetrix(root->left, root->right);
}
