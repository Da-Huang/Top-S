// #redo
int compareVersion(string version1, string version2) {
  int v1begin = 0, v2begin = 0;
  int v1n = version1.size(), v2n = version2.size();

  while (v1begin < v1n || v2begin < v2n) {
    int v1end = version1.find(".", v1begin);
    int v2end = version2.find(".", v2begin);
    if (v1end == -1) v1end = v1n;
    if (v2end == -1) v2end = v2n;

    int v1i = v1begin == v1end ? 0 : stoi(version1.substr(v1begin, v1end - v1begin));
    int v2i = v2begin == v2end ? 0 : stoi(version2.substr(v2begin, v2end - v2begin));
    if (v1i < v2i) return -1;
    if (v1i > v2i) return 1;

    v1begin = min(v1end + 1, v1n);
    v2begin = min(v2end + 1, v2n);
  }
  return 0;
}
