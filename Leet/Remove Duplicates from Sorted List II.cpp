ListNode* deleteDuplicates(ListNode* head) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  while (ptr->next) {
    ListNode *q = ptr->next;
    if (q->next && q->next->val == ptr->next->val) {
      while (q->next && q->next->val == ptr->next->val) {
        ListNode *node = q->next;
        q->next = node->next;
        delete node;
      }
      ListNode *node = ptr->next;
      ptr->next = node->next;
      delete node;
    } else ptr = ptr->next;
  }
  return HEAD.next;
}
