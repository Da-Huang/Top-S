void deleteNode(ListNode* node) {
  if (node == nullptr || node->next == nullptr) return;
  ListNode *ptr = node->next;
  node->val = ptr->val;
  node->next = ptr->next;
  delete ptr;
}
