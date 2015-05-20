TreeNode* __inorder(int first, int last, ListNode *&ptr) {
  if (first > last) return NULL;
  int mid = first + (last - first) / 2;
  TreeNode *left = __inorder(first, mid - 1, ptr);
  TreeNode *root = new TreeNode(ptr->val);
  ptr = ptr->next;
  TreeNode *right = __inorder(mid + 1, last, ptr);
  root->left = left;
  root->right = right;
  return root;
}

TreeNode* sortedListToBST(ListNode* head) {
  int N = 0;
  for (ListNode *ptr = head; ptr; ptr = ptr->next) ++ N;
  return __inorder(0, N - 1, head);
}
