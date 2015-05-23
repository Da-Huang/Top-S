ListNode* swapPairs(ListNode* head) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  while (ptr->next) {
    ListNode *q = ptr->next;
    ListNode *node = q->next;
    if (node == NULL) break;
    q->next = node->next;
    node->next = q;
    ptr->next = node;
    ptr = q;
  }
  return HEAD.next;
}
