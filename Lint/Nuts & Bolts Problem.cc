// #redo
void __sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts,
                        Comparator comparator, int first, int last) {
  if (first >= last) return;
  int less_count = 0, equal_index = -1;
  for (int i = first; i <= last; ++i) {
    int cmp = comparator.cmp(nuts[first], bolts[i]);
    if (cmp > 0)
      ++less_count;
    else if (cmp == 0)
      equal_index = i;
  }
  swap(bolts[equal_index], bolts[first + less_count]);
  int i = first, j = last;
  while (i < j) {
    int cmpi = comparator.cmp(nuts[first], bolts[i]);
    int cmpj = comparator.cmp(nuts[first], bolts[j]);
    if (cmpi > 0)
      ++i;
    else if (cmpj < 0)
      --j;
    else
      swap(bolts[i++], bolts[j--]);
  }
  swap(nuts[first], nuts[first + less_count]);
  i = first, j = last;
  while (i < j) {
    int cmpi = comparator.cmp(nuts[i], bolts[first + less_count]);
    int cmpj = comparator.cmp(nuts[j], bolts[first + less_count]);
    if (cmpi < 0)
      ++i;
    else if (cmpj > 0)
      --j;
    else
      swap(nuts[i++], nuts[j--]);
  }
  __sortNutsAndBolts(nuts, bolts, comparator, first, first + less_count - 1);
  __sortNutsAndBolts(nuts, bolts, comparator, first + less_count + 1, last);
}

void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts,
                      Comparator compare) {
  __sortNutsAndBolts(nuts, bolts, compare, 0, (int)nuts.size() - 1);
}
