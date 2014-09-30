char *strStr(char *haystack, char *needle) {
  const int H = strlen(haystack);
  const int N = strlen(needle);
  int next[N];
  if ( N == 0 ) return haystack;
  next[0] = -1;
  int i = 1;
  int j = next[0];
  while ( i < N ) {
    if ( j < 0 ) next[i ++] = ++ j;
    else if ( needle[i - 1] == needle[j] ) next[i ++] = ++ j;
    else j = next[j];
  }

  i = 0; j = 0;
  while ( i < H && j < N ) {
    if ( j < 0 ) {
      i ++; j ++;

    } else if ( haystack[i] == needle[j] ) {
      i ++; j ++;

    } else j = next[j]; 
  }
  if ( j == N ) return haystack + i - N;
  else return NULL;
}

