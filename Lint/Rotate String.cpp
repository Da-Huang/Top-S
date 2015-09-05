// #redo
void rotateString(string &str, int offset) {
  if (str.empty()) return;
  offset %= str.size();
  reverse(str.begin(), str.end());
  reverse(str.begin(), str.begin() + offset);
  reverse(str.begin() + offset, str.end());
}
