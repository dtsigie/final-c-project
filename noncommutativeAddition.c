#include <stdio.h>

int fun( int* i ) {
  *i += 5;
  return 4;
} // fun( int* )

int id( int i ) {
  return i;
} // id( int )

void main() {
  int x = 3;
  x = id(x) + fun(&x);

  // value of x is now 7
  printf( "%d\n", x );

  x = 3;
  x = fun(&x) + id(x);

  // value of x is now 12
  printf( "%d\n", x );
} // main()

