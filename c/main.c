#include <stdio.h>

int main() {
  int a = 1;
  float b = 2.5;
  char c = 'A';
  printf("a = %d, sizeof(a) = %zu\n", a, sizeof(a));
  printf("b = %.1f, sizeof(b) = %zu\n", b, sizeof(b));
  printf("c = %c, sizeof(c) = %zu\n", c, sizeof(c));
  printf("End of program\n");
  return 0;
}