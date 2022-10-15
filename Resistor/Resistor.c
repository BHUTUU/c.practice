/*BY: Suman Kumar ~BHUTUU
Date: 15-01-2022(saturday)
Question:- Make a program in c to code and decode values and colors respectively of resistors by taking input from user.
*/
#include <stdio.h>
int main() {
  int a, b, rValue;
  char unit;
  
  printf("Welcome to Resistor ~\n\n");
  printf("Your resistor value unit is [o/k/m]> ");
  scanf("%s", &unit);
  printf("Enter resistor numerical value: ");
  scanf("%d", &b);
  if (unit == 'k') {
    rValue=b*1000;
  }
  printf("%d\n",rValue);
}
