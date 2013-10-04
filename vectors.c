//dawit

#include <stdio.h>
#include <math.h>

#define DIMENSION 2


struct vector {
  double x;
  double y;
  double z;
}; // vector

typedef struct vector Vector;

Vector makeVector(double x, double y, double z){

  Vector newVector;
  newVector.x = x;
  newVector.y = y;
  newVector.z = z;

  return newVector;

}// vector constructor

double dotProduct(Vector a, Vector b){
 
  double dotProduct;
  dotProduct = a.x * b.x + a.y * b.y + a.z * b.z;
  return dotProduct;

}// returns dot product of two vectors

void printVector ( Vector a){
  printf("v =  (%8.4f , %8.4f ,%8.4f )", a.x,a.y,a.z);
}// prints a vector

Vector add(Vector a , Vector b){
  Vector sum;
  sum.x = a.x + b.x;
  sum.y = a.y + b.y;
  sum.z = a.z + b.z;
  return sum;
}// returns the sum of two vectors

Vector diff(Vector a , Vector b){
  Vector diff;
  diff.x = a.x - b.x;
  diff.y = a.y - b.y;
  diff.z = a.z - b.z;
  return diff;
}// returns the difference of two vectors

double magnitude(Vector a){
  double mag;
  mag = sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
  return mag;
}// returns magnitude of the vector

Vector scaleVector( double scaleFactor, Vector v ){
  
  Vector scaledVector;
  scaledVector.x = v.x * scaleFactor;
  scaledVector.y = v.y * scaleFactor;
  scaledVector.z = v.z * scaleFactor;
  return scaledVector;

}// scales a vector by a scalar
Vector normalize( Vector v ){
 
  Vector normalVector;
  normalVector.x = v.x/magnitude(v);
  normalVector.y = v.y/magnitude(v);
  normalVector.z = v.z/magnitude(v);
  return normalVector;

}// returns the normal vector of the input vector
Vector crossProduct( Vector u, Vector v ){
  
  Vector crossProduct;
  crossProduct.x = ( u.y * v.z ) - ( u.z * v.y);
  crossProduct.y = ( u.z * v.x ) - ( u.x * v.z);
  crossProduct.z = ( u.x * v.z ) - ( u.y * v.x);
  return crossProduct;

}// returns cross product of two vectors

