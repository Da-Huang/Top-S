void connect(TreeLinkNode *root) {
  TreeLinkNode *head = root;
  while ( head ) {
    TreeLinkNode *ptr = head;
    TreeLinkNode HEAD(0);
    TreeLinkNode *tail = &HEAD;
    while ( ptr ) {
      if ( ptr->left ) {
        tail->next = ptr->left;
        tail = ptr->left;
      }
      if ( ptr->right ) {
        tail->next = ptr->right;
        tail = ptr->right;
      }
      ptr = ptr->next;
    }
    head = HEAD.next;
  }
}