// Redo
ListNode *rotateRight(ListNode *head, int k) {
  if ( head == NULL ) return NULL;
  int count = 0;
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *tail;
  for (tail = &HEAD; tail->next; tail = tail->next) count ++;
  k = k % count;
  if ( k == 0 ) return head;
  ListNode *ptr = &HEAD;
  for (int i = 0; i < count - k; i ++) ptr = ptr->next;
  tail->next = HEAD.next;
  HEAD.next = ptr->next;
  ptr->next = NULL;
  return HEAD.next;
}

