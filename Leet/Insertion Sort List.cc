// #redo
ListNode* insertionSortList(ListNode* head) {
  if (head == NULL) return NULL;
  ListNode HEAD(0);
  HEAD.next = head;
  while (head->next) {
    ListNode *node = head->next;
    if (node->val >= head->val) head = head->next;
    else {
      ListNode *ptr = &HEAD;
      while (ptr != head && ptr->next->val < node->val) ptr = ptr->next;
      head->next = node->next;
      node->next = ptr->next;
      ptr->next = node;
    }
  }
  return HEAD.next;
}
