#include <stdio.h>

#define SIZE 1000000

int bitmap[SIZE] ;

void filter() {
  int i = 0;
  int j = 2 ;
  
  bitmap[0] = 1;
  bitmap[1] = 1 ;
  for( i = 2; i < SIZE; i++ ) {
    bitmap[i] = 0 ;
  } // for

  i = 2;
  while( i < SIZE ) {
    if( bitmap[i] == 0 ) {
      for( j = i + i; j < SIZE; j += i ) {
        bitmap[j] = 1;
      } // for
    } // if

    i++ ;
  } // while


}

int main( int argc, char** argv ) {
  
  filter() ;

  int i;
  for( i = 0; i < SIZE; i++ ) {
    if( bitmap[i] == 0 ) {
      printf( "%d is prime.\n", i ) ;
    } // if
  } // for

}
