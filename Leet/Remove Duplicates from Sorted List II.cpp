ListNode *deleteDuplicates(ListNode *head) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  while ( ptr->next ) {
    ListNode *q = ptr->next;
    if ( q->next && q->val == q->next->val ) {
      ptr->next = q->next;
      while ( ptr->next && ptr->next->val == q->val ) {
        ListNode *node = ptr->next;
        ptr->next = node->next;
        delete node;
      }
      delete q;
    } else {
      ptr = ptr->next;
    }
  }
  return HEAD.next;
}
