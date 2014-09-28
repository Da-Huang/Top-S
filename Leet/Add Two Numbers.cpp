ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode res(0);
  ListNode *tail = &res;
  int c = 0;
  while ( l1 && l2 ) {
    int v = l1->val + l2->val + c;
    tail->next = new ListNode(v % 10);
    tail = tail->next;
    c = v / 10;
    l1 = l1->next;
    l2 = l2->next;
  }
  while ( l1 ) {
    int v = l1->val + c;
    tail->next = new ListNode(v % 10);
    tail = tail->next;
    c = v / 10;
    l1 = l1->next;
  }
  while ( l2 ) {
    int v = l2->val + c;
    tail->next = new ListNode(v % 10);
    tail = tail->next;
    c = v / 10;
    l2 = l2->next;
  }
  if ( c ) {
    tail->next = new ListNode(c);
    tail = tail->next;
  }
  return res.next;
}


