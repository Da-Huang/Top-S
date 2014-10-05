ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  ListNode HEAD(0);
  ListNode *tail = &HEAD;
  while ( l1 && l2 ) {
    if ( l1->val <= l2->val ) {
      ListNode *node = l1;
      l1 = l1->next;
      tail->next = node;
      tail = node;

    } else {
      ListNode *node = l2;
      l2 = l2->next;
      tail->next = node;
      tail = node;
    }
  }
  if ( l1 ) tail->next = l1;
  else if ( l2 ) tail->next = l2;
  return HEAD.next;
}

