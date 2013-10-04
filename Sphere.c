
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectors.h"

void printPOVPrefix() {
  printf( "#include \"colors.inc\"\n" );
  printf( "#include \"stones.inc\"\n" );
  printf( "global_settings { assumed_gamma 1.0 }\n" );
  printf( "camera {\n" );
  printf( "location <1.2, 1.2, -1.0>\n" );
  printf( "look_at <0.5, 0.5, 0.5>\n" );
  printf( "}\n" );
  printf( "light_source { <2, 4, -2> color White }\n" );
  printf( "light_source { <-1, -1, -8> color White }\n" );
} // printPOVPrefix()

void printSphere( Vector center, double radius, Vector color ) {
  printf( "sphere {" );
  printf( "<%6.3f %6.3f %6.3f,> %6.3f\n", center.x, center.y, center.z, radius ); 
  printf( "texture {pigment {color rgb<%6.3f,%6.3f,%6.3f>}}\n", color.x, color.y, color.z );
  printf( "}\n" );   
} // printSphere( Vector, double, Vector )

double randomDouble() {
  double r = ((double) rand())/RAND_MAX ;
} // randomDouble()

int main( int argc, char** argv ) {
  // Seed the random number generator
  // with the time measured in seconds.
  // "time_t" is a just another name for
  // a long (64 bit) integer.
  time_t t = time(NULL) ;
  srand( t ) ;

  double radius = 0.1;
  Vector spheres[51];
  printPOVPrefix();
  int i; 

  for( i = 0; i < 50; i++ ) {
    double x = randomDouble();
    double y = randomDouble();
    double z = randomDouble();
    Vector center = makeVector( x, y, z );

    spheres[i] = center;	
    
  } // Create spheres located randomly at centers of components with values between 0 & 1
  int j, k;

 for(j = 0; j < 50; j++){
       for(k = 0; k< 50; k++) {
	 if( magnitude ( diff(spheres[j],spheres[k])) > 0.2){
	    printSphere(spheres[j], radius, spheres[j] );
	  }
       }
  }// print non intersecting spheres with colors derived from their center values



	
} // main( int, char** )
