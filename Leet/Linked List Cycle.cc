// #redo
bool hasCycle(ListNode *head) {
  if (head == NULL || head->next == NULL) return false;
  ListNode *p = head, *q = head->next;
  while (q) {
    if (q == p) return true;
    p = p->next;
    q = q->next;
    if (q) q = q->next;
  }
  return false;
}
