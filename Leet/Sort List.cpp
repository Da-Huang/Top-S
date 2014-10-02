// Return next tail
ListNode *merge(ListNode *HEAD, ListNode *MID, ListNode *TAIL) {
  ListNode *nextHead = TAIL->next;
  ListNode *head1 = HEAD->next;
  ListNode *head2 = MID->next;
  ListNode *tail1 = MID;
  ListNode *tail2 = TAIL;
  tail1->next = NULL;
  tail2->next = NULL;
  ListNode *tail = HEAD;
  while ( head1 && head2 ) {
    if ( head1->val < head2->val ) {
      tail->next = head1;
      tail = head1;
      head1 = head1->next;

    } else {
      tail->next = head2;
      tail = head2;
      head2 = head2->next;
    }
  }
  if ( head1 ) {
    tail->next = head1;
    tail = tail1;
  }
  if ( head2 ) {
    tail->next = head2;
    tail = tail2;
  }
  tail->next = nextHead;
  return tail;
}

ListNode *sortList(ListNode *head) {
  ListNode HEAD(0);
  HEAD.next = head;
  int n = 1;
  while ( true ) {
    ListNode *subHead = &HEAD;
    while ( true ) {
      ListNode *tail1 = subHead;
      for (int i = 0; i < n; i ++) {
        if ( tail1->next == NULL ) break;
        tail1 = tail1->next;
      }
      if ( tail1->next == NULL ) break;
      ListNode *tail2 = tail1;
      for (int i = 0; i < n; i ++) {
        if ( tail2->next == NULL ) break;
        tail2 = tail2->next;
      }
      subHead = merge(subHead, tail1, tail2);
    }
    n <<= 1;
    if ( subHead == &HEAD ) return HEAD.next;
  }
}

