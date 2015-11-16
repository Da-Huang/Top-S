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

// #version2
ListNode *__reverse(ListNode *head) { // head must not be nullptr
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
  if (head == nullptr || head->next == nullptr) return true; 
  // At least, two nodes
  ListNode* half = head, *p = head->next;
  while (p) {
    p = p->next;
    if (p) {
      p = p->next;
      half = half->next;
    }
  }
  ListNode *head2 = half->next; // head2 != nullptr
  head2 = __reverse(head2);
  ListNode *ptr1 = head, *ptr2 = head2;
  bool ans = true;
  while (ptr2) {
    if (ptr1->val != ptr2->val) {
      ans = false;
      break;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  half->next = __reverse(head2);
  return ans;
}
