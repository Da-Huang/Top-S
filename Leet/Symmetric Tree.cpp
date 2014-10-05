bool __isSymmetric(TreeNode *l, TreeNode *r) {
  if ( l == NULL && r == NULL ) return true;
  if ( l == NULL ) return false;
  if ( r == NULL ) return false;
  return l->val == r->val && __isSymmetric(l->left, r->right) && __isSymmetric(l->right, r->left);
}

bool isSymmetric(TreeNode *root) {
  if ( root == NULL ) return true;
  return __isSymmetric(root->left, root->right);
}

