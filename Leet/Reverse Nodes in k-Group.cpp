// Redo
ListNode *__reverse(ListNode *HEAD, ListNode *tail) {
  ListNode *nextHead = tail->next;
  ListNode *newTail = HEAD->next;
  while ( newTail->next != nextHead ) {
    ListNode *node = newTail->next;
    newTail->next = node->next;
    node->next = HEAD->next;
    HEAD->next = node;
  }
  return newTail;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  if ( k <= 1 ) return head;
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  while ( true ) {
    ListNode *q = ptr;
    int i = 0;
    while ( i < k ) {
      if ( q->next == NULL ) break;
      q = q->next;
      i ++;
    }
    if ( i < k ) break;
    ptr = __reverse(ptr, q);
  }
  return HEAD.next;
}

