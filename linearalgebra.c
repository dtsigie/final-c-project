
// linearalgebra.c
// Dawit Tsigie
// 4 October 2013
// C PROJECT
// 


#include <stdio.h>
#include <math.h>

#define DIMENSION 2

struct matrix {
  double element[DIMENSION][DIMENSION];
}; // matrix

typedef struct matrix Matrix;

Matrix scaling(double a , double b){
 Matrix m;
 m.element[0][0] = a;
 m.element[0][1] = 0;
 m.element[1][0] = 0;
 m.element[1][1] = b;
 return m;
}// scaling( double, double )

/*Matrix rotation(double theta){
 Matrix m;
 m.element[0][0] = cos (theta);
 m.element[0][1] = -sin (theta);
 m.element[1][0] = sin (theta);
 m.element[1][1] = cos (theta);
 return m;
}
*/
Matrix identity(){
 Matrix m;
 m.element[0][0] = 1;
 m.element[0][1] = 0;
 m.element[1][0] = 0;
 m.element[1][1] = 1;
 return m;
}

Matrix matrMult(Matrix a , Matrix b){

 Matrix product;
 product.element[0][0] = (a.element[0][0] * b.element[0][0]) + (a.element[0][1] * b.element[1][0]) ;
 product.element[0][1] = (a.element[0][0] * b.element[0][1]) + (a.element[0][1] * b.element[1][1]) ;

 product.element[1][0] = (a.element[1][0] * b.element[0][0]) + (a.element[1][1] * b.element[1][0]) ;
 product.element[1][1] = (a.element[1][0] * b.element[0][1]) + (a.element[1][1] * b.element[1][1]) ;
return product;

} // multiplies two matrices

int main( int argc, char** argv ) {
  // Create a 2 x 2 matrix
  Matrix a;
  a.element[0][0] = 3;
  a.element[0][1] = 4;
  a.element[1][0] = 6;
  a.element[1][1] = 5;
  // Create a 2 x 2 matrix
  Matrix b;
  b.element[0][0] = 2;
  b.element[0][1] = 3;
  b.element[1][0] = 4;
  b.element[1][1] = 5;
  // Print the 2 x 2 identity matrix.
  int i;
  for( i = 0; i < DIMENSION; i++ ) {
    int j;
    for( j = 0; j < DIMENSION; j++ ) {
      printf( "%8.4f ", a.element[i][j] );
    } // for
    printf( "\n" );
  } // for
printf("\n"
  for( i = 0; i < DIMENSION; i++ ) {
    int j;
    for( j = 0; j < DIMENSION; j++ ) {
      printf( "%8.4f ", b.element[i][j] );
    } // for
    printf( "\n" );
  } // for
  
printf("the product of the two matrices is:\n ");
Matrix matrixMulti = matrMult(a,b);
 for( i = 0; i < DIMENSION; i++ ) {
    int j;
    for( j = 0; j < DIMENSION; j++ ) {
      printf( "%8.4f ", matrixMulti.element[i][j] );
    } // for
    printf( "\n" );
  } // for
  


} // main( int, char** )
