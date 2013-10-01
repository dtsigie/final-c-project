#include <stdio.h>
void main ( int argc, char** argv){ 
  int key = atoi( argv[1] );  
  printf("%d",key);
  char letter; 

   while ( scanf ("%c", &letter) != EOF ) { 
     if ( 'a'<= letter && letter <= 'Z' ) {
       printf ("%c" , letter) ;
     }
   }
 }
