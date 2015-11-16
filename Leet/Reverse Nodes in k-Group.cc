ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  while (ptr->next) {
    int count = 0;
    for (ListNode *q = ptr; q->next; q = q->next) ++ count;
    if (count < k) break;
    ListNode *tail = ptr->next;
    for (int i = 0; i < k - 1; ++ i) {
      ListNode *node = tail->next;
      tail->next = node->next;
      node->next = ptr->next;
      ptr->next = node;
    }
    ptr = tail;
  }
  return HEAD.next;
}
