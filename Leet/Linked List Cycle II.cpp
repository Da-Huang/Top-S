ListNode *detectCycle(ListNode *head) {
  if ( head == NULL || head->next == NULL ) return NULL;
  ListNode *slow = head, *fast = head->next;
  int L = 0;
  while ( fast && fast->next ) {
    if ( slow == fast ) break;
    fast = fast->next->next;
    slow = slow->next;
    L ++;
  }
  if ( slow != fast ) return NULL;
  int C = 1;
  ListNode *ptr = fast->next;
  while ( ptr != fast ) {
    ptr = ptr->next;
    C ++;
  }
  ListNode *p1 = head;
  ListNode *p2 = fast;
  while ( L > C ) {
    p1 = p1->next;
    L --;
  }
  while ( C > L ) {
    p2 = p2->next;
    C --;
  }
  while ( p1 != p2 ) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1;
}
