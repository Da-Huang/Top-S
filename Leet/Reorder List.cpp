void reorderList(ListNode *head) {
  if ( head == NULL || head->next == NULL ) return;
  ListNode *p = head, *q = head;
  while ( q->next ) {
    q = q->next;
    if ( q->next ) {
      q = q->next;
      p = p->next;
    }
  }
  ListNode *head2 = p->next;
  p->next = NULL;
  ListNode *ptr = head2;
  while ( ptr->next ) {
    ListNode *node = ptr->next;
    ptr->next = node->next;
    node->next = head2;
    head2 = node;
  }
  p = head;
  q = head2;
  while ( q ) {
    ListNode *node = q;
    q = node->next;
    node->next = p->next;
    p->next = node;
    p = node->next;
  }
}

