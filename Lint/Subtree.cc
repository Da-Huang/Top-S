// #redo
bool __isIdentical(TreeNode *T1, TreeNode *T2) {
  if (T1 == nullptr && T2 == nullptr) return true;
  if (T1 == nullptr || T2 == nullptr) return false;
  if (T1->val != T2->val) return false;
  return __isIdentical(T1->left, T2->left) && __isIdentical(T1->right, T2->right);
}
 
bool isSubtree(TreeNode *T1, TreeNode *T2) {
  if (T2 == nullptr) return true;
  if (T1 == nullptr) return false;
  if (__isIdentical(T1, T2)) return true;
  return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}
