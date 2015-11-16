bool isUnique(string &str) {
  vector<bool> cset(128);
  for (char c : str) {
    if (cset[c]) return false;
    cset[c] = true;
  }
  return true;
}
