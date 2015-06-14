ListNode* reverseList(ListNode* head) {
  if (head == NULL) return head;
  ListNode *tail = head;
  while (tail->next) {
    ListNode *node = tail->next;
    tail->next = node->next;
    node->next = head;
    head = node;
  }
  return head;
}
