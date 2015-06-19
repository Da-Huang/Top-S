// #redo
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  int interArea = 0;
  if (min(C, G) > max(A, E) && min(D, H) > max(B, F))
    interArea = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
  return (D - B) * (C - A) - interArea + (G - E) * (H - F);
}
