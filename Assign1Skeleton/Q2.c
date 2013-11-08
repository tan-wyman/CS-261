/* CS 261 - Assignment 1 - Q2 
 * Name: Wyman Tan
 * Date: 4-10-13
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int *a, int *b, int c) {
	/* Set a to double its original value */
	*a *=  2;
	/* Set b to half its original value */
	*b /= 2;
	/* Assign a+b to c */
	c = *a + *b;
	/* Return c */
	return c;
}

int main(int argc, char **argv) {
	/* Declare three integers x, y, z and initialize them to 5, 6, 7 respectively */
	int x = 5;
	int y = 6;
	int z = 7;
	/* Print the values of x, y, z */
	printf("x = %d \t y = %d \t z = %d\n", x, y, z); 
	/* Call foo() appropriately, passing x, y, z as parameters */
	int tmp = foo(&x, &y, z);
	/* Print the value returned by foo */
	printf("foo returns: %d\n", tmp);
	/* Print the values of x, y, z again */
	printf("x = %d \t y = %d \t z = %d\n", x, y, z); 
	/* Is the return value different than the value of z?  Why? */
	printf("foo returns a different value than z because foo only "
			"changes its local copy of z that was passed-by-value, "
			"rather than the actual value of z, which would need to "
			"be passed-by-reference to actually change z.\n");
	return 0;
}


