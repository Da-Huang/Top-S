ListNode* removeElements(ListNode* head, int val) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  while (ptr->next) {
    if (ptr->next->val == val) {
      ListNode *node = ptr->next;
      ptr->next = node->next;
      delete node;
    } else ptr = ptr->next;
  }
  return HEAD.next;
}
