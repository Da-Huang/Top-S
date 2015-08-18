int replaceBlank(char string[], int length) {
  int count = 0;
  for (int i = 0; i < length; ++i) if (string[i] == ' ') ++count;
  int ans_length = length + 2 * count;
  int i = length - 1, j = ans_length - 1;
  while (i >= 0) {
    if (string[i] == ' ') {
      string[j--] = '0';
      string[j--] = '2';
      string[j--] = '%';
    } else {
      string[j--] = string[i];
    }
    --i;
  }
  return ans_length;
}
