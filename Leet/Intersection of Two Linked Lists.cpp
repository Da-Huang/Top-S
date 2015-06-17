ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int NA = 0;
  for (ListNode *ptr = headA; ptr; ptr = ptr->next) ++ NA;
  int NB = 0;
  for (ListNode *ptr = headB; ptr; ptr = ptr->next) ++ NB;

  while (NA > NB) {
    headA = headA->next;
    -- NA;
  }
  while (NB > NA) {
    headB = headB->next;
    -- NB;
  }

  while (headA && headA != headB) {
    headA = headA->next;
    headB = headB->next;
  }
  return headA;
}
