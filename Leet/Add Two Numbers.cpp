// #redo
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int c = 0;
  ListNode HEAD(0);
  ListNode *tail = &HEAD;
  while (l1 && l2) {
    int p = l1->val + l2->val + c;
    tail->next = new ListNode(p % 10);
    tail = tail->next;
    c = p / 10;
    l1 = l1->next;
    l2 = l2->next;
  }
  while (l1) {
    int p = l1->val + c;
    tail->next = new ListNode(p % 10);
    tail = tail->next;
    c = p / 10;
    l1 = l1->next;
  }
  while (l2) {
    int p = l2->val + c;
    tail->next = new ListNode(p % 10);
    tail = tail->next;
    c = p / 10;
    l2 = l2->next;
  }
  if (c) tail->next = new ListNode(c);
  return HEAD.next;
}
