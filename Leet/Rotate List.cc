// Redo
ListNode* rotateRight(ListNode* head, int k) {
  if (head == NULL) return NULL;
  int N = 1;
  ListNode *tail = head;
  for (; tail->next; tail = tail->next) ++ N;
  k %= N;
  if (k == 0) return head;
  ListNode *ptr = head;
  for (int i = 0; i < N - k - 1; ++ i) ptr = ptr->next;
  ListNode *q = ptr->next;
  ptr->next = NULL;
  tail->next = head;
  return q;
}
