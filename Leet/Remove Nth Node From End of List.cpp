// Method 1
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  for (int i = 0; i < n; i ++) {
    ptr = ptr->next;
    if ( ptr == NULL ) return NULL;
  }
  ListNode *q = &HEAD;
  while ( ptr->next ) {
    ptr = ptr->next;
    q = q->next;
  }
  ListNode *node = q->next;
  q->next = node->next;
  delete node;
  return HEAD.next;
}

// Method 2
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *cache[n];
  int i = 0;
  for (ListNode *ptr = &HEAD; ptr->next; ptr = ptr->next) {
    cache[i ++ % n] = ptr;
  }
  ListNode *ptr = cache[i % n];
  ListNode *node = ptr->next;
  ptr->next = node->next;
  delete node;
  return HEAD.next;
}
