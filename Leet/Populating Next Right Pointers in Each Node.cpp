void connect(TreeLinkNode *root) {
  TreeLinkNode HEAD(0);
  HEAD.next = root;
  while (HEAD.next) {
    TreeLinkNode *head = HEAD.next;
    HEAD.next = NULL;
    TreeLinkNode *tail = &HEAD;
    while (head) {
      if (head->left) {
        tail->next = head->left;
        tail = head->left;
      }
      if (head->right) {
        tail->next = head->right;
        tail = head->right;
      }
      head = head->next;
    }
  }
}
