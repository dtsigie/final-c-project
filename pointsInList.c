
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * This program writes an HTML file that
 * contains an SVG image of a complete graph.
 *
 * Your mission is to complete the definition
 * of the addPoint() function.
 *
 * Compile by typing: gcc agent99.c -lm -o agent99
 * Run the program by typing: agent99 8 > agent99.html
 * View the result by opening the file "agent99.html" 
 *   in a browser.
 */

struct point {
  int id;
  double x;
  double y;
} ;

typedef struct point Point, *PointPointer;

struct node {
  PointPointer pp;
  struct node *np;
} ;

typedef struct node Node, *NodePointer;

// Keep track of the location of the
// first element of a linked list.
// (That location is initially null because
// the list is initially empty.)
static NodePointer head = NULL;

// Create a point and add it to a linked list.
NodePointer addPoint( double x, double y ) {
  static int count = 0;

  NodePointer vp = (NodePointer) malloc( sizeof( Node ) );
  vp->pp = (PointPointer) malloc( sizeof( Point ) );
  vp->pp->id = count;
  vp->pp->x = x;
  vp->pp->y = y;
  vp->np = head;

  count++;

  return vp;
} // addPoint( double, double )


int main( int argc, char** argv ) {
  
  // Set number of vertices.
  // Assign default value or
  // value found in command line parameter (if present).
  int n = 12;
  if( argc > 1 ) {
    n = atoi(argv[1]);
  } // if

  // Compute and store the coordinates of the vertices.
  int i;
  for( i = 0; i < n; i++ ) {
    double fraction = ((double) i)/n;
    double angle = 2 * M_PI * fraction;
    double x = cos( angle );
    double y = sin( angle );
    head = addPoint( x, y );
  } // for

  // Write the first tags for the HTML file.
  printf( "<html>\n" );
  printf( "<body>\n" );
  printf( "<h1>A Complete Graph</h1>\n" );

  // You can get a different picture by
  // changing the numbers that follow.
  int red = 0;
  int green = 192;
  int blue = 224;

  int radius = 128;
 
  int lineWidth = 2;

  // Write the tag that tells the browser that
  // what follows is a description of graphics
  // written in SVG and also tells the browser
  // how much space to allow for the image.
  printf( "<svg xmlns=\"http://www.w3.org/2000/svg\" \n" );
  printf( "\tversion=\"1.1\" height=\"%d\" width=\"%d\"> \n",
	  2 * radius, 2 * radius );

  // Nested loops here find every
  // pair of distinct vertices.
  NodePointer ip = head;
  while( ip != NULL ) {
    NodePointer jp = head;
    while( jp != NULL ) {
      // Checking id numbers is a way of avoiding
      // drawing lines that connect a vertex to itself.
      if( ip->pp->id != jp->pp->id ) {
        // Compute the coordinates of the endpoints
        // of a line segment.
        int x0 = (int) (radius + radius * ip->pp->x);
        int y0 = (int) (radius + radius * ip->pp->y);
        int x1 = (int) (radius + radius * jp->pp->x);
        int y1 = (int) (radius + radius * jp->pp->y);

        // Write the SVG that describes a line segment.
        printf( "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\"\n",
		x0, y0, x1, y1 );
        printf( "\tstyle=\"stroke:rgb(%d, %d, %d);stroke-width:%d\"/>\n",
                red, green, blue, lineWidth );

      } // if
      jp = jp->np;
    } // while
    ip = ip->np;
  } // while

  // Write the last tags for the HTML  file.
  printf( "</svg>\n" );
  printf( "</body>\n" );
  printf( "</html>\n" ); 
  
} // main( int, char** )
