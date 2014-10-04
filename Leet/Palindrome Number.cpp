bool isPalindrome(int x) {
  if ( x < 0 ) return false;
  if ( x == 0 ) return true;
  int high = 1;
  while ( (x / high) >= 10 ) high *= 10;
  int low = 1;
  while ( high > low ) {
    if ( (x / high) % 10 != (x / low) % 10 ) return false;
    high /= 10;
    low *= 10;
  }
  return true;
}

