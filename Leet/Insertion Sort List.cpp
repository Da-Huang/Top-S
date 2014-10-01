ListNode *insertionSortList(ListNode *head) {
  if ( head == NULL ) return NULL;
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = head;
  while ( ptr->next ) {
    ListNode *node = ptr->next;
    if ( node->val > ptr->val ) {
      ptr = node;
    } else {
      ListNode *q = &HEAD;
      while ( q->next && q->next->val < node->val ) q = q->next;
      ptr->next = node->next;
      node->next = q->next;
      q->next = node;
    }
  }
  return HEAD.next;
}

