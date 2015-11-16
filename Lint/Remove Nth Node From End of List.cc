ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *q = &HEAD;
  for (int i = 0; i < n; ++i) q = q->next;
  ListNode *p = &HEAD;
  for (; q->next; q = q->next) p = p->next;
  ListNode *node = p->next;
  p->next = node->next;
  delete node;
  return HEAD.next;
}
