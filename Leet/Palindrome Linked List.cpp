// #redo
ListNode *__reverse(ListNode *head) {
  ListNode *tail = head;
  while (tail->next) {
    ListNode *node = tail->next;
    tail->next = node->next;
    node->next = head;
    head = node;
  }
  return head;
}

bool isPalindrome(ListNode* head) {
  int n = 0;
  for (ListNode *ptr = head; ptr; ptr = ptr->next) ++n;
  if (n <= 1) return true;
  ListNode *half = head;
  for (int i = 0; i < (n-1)/2; ++i) half = half->next;
  ListNode *tail = half->next;
  half->next = __reverse(half->next);
  bool ans = true;
  for (ListNode *ptr = half->next; ptr; ptr = ptr->next) {
    if (head->val != ptr->val) {
      ans = false;
      break;
    }
    head = head->next;
  }
  half->next = __reverse(half->next);
  return ans;
}
