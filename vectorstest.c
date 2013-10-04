//dawit

#include <stdio.h>
#include "vectors.h"


int main( int argc, char** argv ) {
 
  Vector a = makeVector(3.0,4.0,5.0);
  Vector b = makeVector(4.0,6.0,9.0);
  printVector(a);
  printf("\n");
  printVector(b);
  printf("\n");
  
  Vector sum;
  sum  = add(a,b);
  printf("Sum of the Vectors: ");
  printVector(sum);   //prints sum of two vectors
  printf("\n"); 
/*
  Vector difference;
  difference = diff(a,b);
  printf("Difference of the Vectors: ");
  printVector(diff);   //prints difference of two vectors
  printf("\n"); 
*/
 
  Vector crossProd;
  crossProd = crossProduct(a,b);
  printf("The cross product of the Vectors: ");
  printVector(crossProd);   //prints the cross product of two vectors
  printf("\n"); 

  double dotProd = dotProduct(a,b);
  printf("Dot product of the two vectors: %5.5f ", dotProd); // prints   dot product of the two vectors
  printf("\n");

  double magA = magnitude(a);
  printf("Magnitude of vector 'a': %5.5f ", magA);// prints the magnitude of the vector
  printf("\n");
  double magB  = magnitude (b);
  printf("Magnitude of vector 'b': %5.5f ", magB);// prints the magnitude of the vector
  printf("\n");

  
  
  return 0;
 

  

} // main( int, char** )
