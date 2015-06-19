void connect(TreeLinkNode *root) {
  TreeLinkNode HEAD(0);
  HEAD.next = root;
  while (HEAD.next) {
    TreeLinkNode *tail = &HEAD;
    TreeLinkNode *ptr = HEAD.next;
    HEAD.next = NULL;
    for (; ptr; ptr = ptr->next) {
      if (ptr->left) {
        tail->next = ptr->left;
        tail = tail->next;
      }
      if (ptr->right) {
        tail->next = ptr->right;
        tail = tail->next;
      }
    }
  }
}
