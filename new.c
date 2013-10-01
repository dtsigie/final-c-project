#include <stdio.h>

void main (){
 
  int n = 17;
  int* np = &n;
  *np = 19;
  printf( "%d\n", n );
  printf("%d\n", *np);

}
