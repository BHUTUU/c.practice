#include <stdio.h>
#include <stdlib.h>


int main() {
  int first=19, terms=7, diff=-3, value, i;

  value = first;
  for(i = 0; i < terms; i++) {
    printf("%d ", value);
    value = value + diff;
  }

  printf("\nAre required terms\n");

 return 0;
}

