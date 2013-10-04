
// dawit
#include <stdio.h>
#include <math.h>

#define DIMENSION 3


struct vector {
  double x;
  double y;
  double z;
}; // vector

typedef struct vector Vector;
Vector makeVector(double x, double y, double z);
double dotProduct(Vector a, Vector b);
void printVector ( Vector a);
Vector add(Vector a , Vector b);
double magnitude(Vector a);
Vector diff( Vector u, Vector v );

Vector scaleVector( double scaleFactor, Vector v );
Vector normalize( Vector v );
Vector crossProduct( Vector u, Vector v );
