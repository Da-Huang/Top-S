// #redo
ListNode* reverseBetween(ListNode* head, int m, int n) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  for (int i = 1; i < m && ptr->next; ++ i) ptr = ptr->next;
  ListNode *tail = ptr->next;
  if (tail == NULL) return head;
  for (int i = m; i < n && tail->next; ++ i) {
    ListNode *node = tail->next;
    tail->next = node->next;
    node->next = ptr->next;
    ptr->next = node;
  }
  return HEAD.next;
}
