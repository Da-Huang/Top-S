// #redo
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode HEAD(0);
  ListNode *tail = &HEAD;
  int c = 0;
  while (l1 || l2 || c) {
    int p = c;
    if (l1) {
      p += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      p += l2->val;
      l2 = l2->next;
    }
    tail->next = new ListNode(p % 10);
    tail = tail->next;
    c = p / 10;
  }
  return HEAD.next;
}
