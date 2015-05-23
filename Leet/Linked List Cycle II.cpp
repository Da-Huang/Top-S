ListNode *detectCycle(ListNode *head) {
  if (head == NULL) return NULL;
  ListNode *p = head, *q = head->next;
  while (q) {
    if (p == q) break;
    p = p->next;
    q = q->next;
    if (q) q = q->next;
  }
  if (q == NULL) return NULL;

  int L = 0;
  for (p = head; p != q; p = p->next) ++ L;
  int C = 1;
  for (p = q->next; p != q; p = p->next) ++ C;

  p = head;
  while (L > C) {
    p = p->next;
    -- L;
  }
  while (L < C) {
    q = q->next;
    -- C;
  }

  while (p != q) {
    p = p->next;
    q = q->next;
  }
  return p;
}
