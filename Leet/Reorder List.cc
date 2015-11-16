void reorderList(ListNode* head) {
  if (head == NULL || head->next == NULL) return;
  int n = 0;
  for (ListNode *ptr = head; ptr; ptr = ptr->next) ++ n;
  ListNode *tail = head;
  for (int i = 0; i < (n-1)/2; ++ i) tail = tail->next;
  ListNode *head2 = tail->next;
  tail->next = NULL;

  ListNode *tail2 = head2;
  while (tail2->next) {
    ListNode *node = tail2->next;
    tail2->next = node->next;
    node->next = head2;
    head2 = node;
  }

  ListNode *ptr = head;
  while (head2) {
    ListNode *node = head2;
    head2 = head2->next;
    node->next = ptr->next;
    ptr->next = node;
    ptr = node->next;
  }
}
