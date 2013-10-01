

// An illustration of several features
// of the C programming language.
//   1) preprocessor directives (#include and #define)
//   2) header files (stdio.h, stdlib.h, time.h, math.h)
//   3) typedefs
//   4) structs
//   5) library functions (malloc(), srand(), rand(), log())
//   6) casts 
//   7) pointers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MEAN_SERVICE_TIME 2.0
#define MEAN_INTERARRIVAL_TIME 3.0

typedef struct process ProcessRecord, *ProcessRecordPointer ;

struct process {
  int id ;
  double timeToService ;
  double timeUntilNextProcess ;
  ProcessRecordPointer np ;
} ;

int main( int argc, char **argv ) {

  // Seed the random number generator
  // with the time measured in seconds.
  // "time_t" is a just another name for
  // a long (64 bit) integer.
  time_t t = time(NULL) ;
  srand( t ) ;

  // NULL is a constant defined for us.
  // (It is zero.)
  ProcessRecordPointer rootPointer = NULL ;
  ProcessRecordPointer pp = NULL ;
  ProcessRecordPointer cp = NULL ;

  // Must declare counter before beginning loop!
  int i ;
  for( i = 0; i < 12; i++ ) {
    // malloc() is the function for "memory allocation"
    // sizeof is an operator that tells us how many bytes
    // we'll need to store an object of a given type.
    // malloc() returns a general kind of pointer (void *)
    // so we must cast it to remind the compiler to what 
    // kind of object we are pointing.
    cp = (ProcessRecordPointer) malloc( sizeof(ProcessRecord) ) ;
    cp->id = i ;

    double r = ((double) rand())/RAND_MAX ;
    
    cp->timeToService = -MEAN_SERVICE_TIME * log(r) ;

    r = ((double) rand())/RAND_MAX ;

    cp->timeUntilNextProcess = -MEAN_INTERARRIVAL_TIME * log(r) ;
    

    cp->np = pp ;
    pp = cp ;
  } // for
  rootPointer = cp ;

  // Traverse the list.
  // Begin at the last element added to the list
  // and end with the first element we added to the list.
  while( cp != NULL ) {
    printf( "process id = %d\n", cp->id ) ;
    printf( "\t service time = %8.4f\n", cp->timeToService ) ;
    printf( "\t interarrival time = %8.4f\n", cp->timeUntilNextProcess ) ;
    cp = cp->np ;
  } // while
  
} // main( int, char** )

