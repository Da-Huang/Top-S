ListNode *nthToLast(ListNode *head, int n) {
  ListNode *q = head;
  for (int i = 0; i < n; ++i) q = q->next;
  ListNode *p = head;
  for (; q; q = q->next) p = p->next;
  return p;
}
