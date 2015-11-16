ListNode* sortList(ListNode* head) {
  int n = 1;
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *tail = &HEAD;
  while (true) {
    ListNode *tail1 = tail;
    for (int i = 0; i < n && tail1->next; ++ i) tail1 = tail1->next;
    if (tail1->next == NULL && tail == &HEAD) break;

    ListNode *tail2 = tail1;
    for (int i = 0; i < n && tail2->next; ++ i) tail2 = tail2->next;

    ListNode *nextHead = tail2->next;
    ListNode *head1 = tail->next, *head2 = tail1->next;
    tail1->next = NULL, tail2->next = NULL;
    while (head1 && head2) {
      ListNode *node;
      if (head1->val <= head2->val) {
        node = head1;
        head1 = head1->next;
      } else {
        node = head2;
        head2 = head2->next;
      }
      tail->next = node;
      tail = node;
    }
    if (head1) {
      tail->next = head1;
      tail = tail1;
    }
    if (head2) {
      tail->next = head2;
      tail = tail2;
    }
    tail->next = nextHead;
    if (nextHead == NULL) {
      tail = &HEAD;
      n <<= 1;
    }
  }
  return HEAD.next;
}
