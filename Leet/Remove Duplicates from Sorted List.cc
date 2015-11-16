ListNode* deleteDuplicates(ListNode* head) {
  if (head == NULL) return NULL;
  ListNode *ptr = head;
  while (ptr->next) {
    if (ptr->next->val == ptr->val) {
      ListNode *node = ptr->next;
      ptr->next = node->next;
      delete node;
    } else ptr = ptr->next;
  }
  return head;
}
