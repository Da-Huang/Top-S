// Redo
TreeNode *__sortedListToBST(ListNode *head, int first, int last, ListNode *&h) {
  if ( first > last ) return NULL;
  const int mid = (first + last) / 2; // TODO
  TreeNode *left = __sortedListToBST(head, first, mid - 1, h);
  TreeNode *root = new TreeNode(h->val);
  h = h->next;
  TreeNode *right = __sortedListToBST(head, mid + 1, last, h);
  root->left = left;
  root->right = right;
  return root;
}

TreeNode *sortedListToBST(ListNode *head) {
  if ( head == NULL ) return NULL;
  int N = 0;
  for (ListNode *ptr = head; ptr; ptr = ptr->next) N ++;
  ListNode *h = head;
  return __sortedListToBST(head, 0, N - 1, h);
}

