#include <stdio.h>

int areaOfRect(int length, int width) {
  int area;
  area = length * width;
  return area;
}

int main() {
  int l = 10, b = 5;
  int area = areaOfRect(l, b);
  printf("%d\n", area);

  return 0;
}
