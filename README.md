Vectors, Matrices, and Non intersecting Spheres
Dawit Tsigie
CSC 315
10/04/13

files included: vectors.c, vectors.h, linearalgebra.c, vectorstest.c, Sphere.c

Vectors- I implemented different methods in the vectors.c programs for different types of vector calculations such as a dot product method, a cross product method, a magnitude method, a difference method, a normalize method and a scale vector method. So I basically implemented  functions to help with some of the principal vector calculations that we perform.

Matrices - I implemented a few methods such as a constructor for a scaling matrix, a rotation matrix and  implemented a method which finds the product of two matrices.

Non - intersecting spheres- I set out to to print out non-intersecting spheres by comparing the distance between the center of the spheres and the sum of their radiuses. 

How to run

1. Vectors- type :  gcc vectors.c -c
		    gcc vectorstest.c -c
		    gcc vectorstest.o vectors.o -o vectorstest -lm
		    ./vectorstest

2. Matrices- type:  gcc linearalgebra.c
	            ./linearalgebra

3. Sphere - type :  gcc sphere.c -c
		    gcc vectors.c -c
		    gcc sphere.o vectors.o -o sphere -lm
		    ./sphere > spheres.pov
		    povray +Ispheres.pov Width=512 Height=512 Display=true +P

