ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode HEAD(0);
  ListNode *tail = &HEAD;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      tail->next = l1;
      tail = l1;
      l1 = l1->next;

    } else {
      tail->next = l2;
      tail = l2;
      l2 = l2->next;
    }
  }
  if (l1) tail->next = l1;
  else if (l2) tail->next = l2;
  return HEAD.next;
}
