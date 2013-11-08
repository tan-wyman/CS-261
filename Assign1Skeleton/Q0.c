/* CS 261 - Assignment 1 - Q0
 * Name: Wyman Tan <tanw>tanw
 * Date: 4-8-13
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int *iptr) {
	/* Print the value pointed to by iptr */
	printf("Value pointed by iptr %d\n", *iptr);
	/* Print the address pointed to by iptr */
	printf("Address pointed to by  iprt %p\n", iptr); 
	/* Print the address of iptr itself */
	printf("Address of iptr %p\n", &iptr);

}

int main() {
	/* Declare an integer x */
	int x = 3;
	/* Print the address of x */
	printf("The address of x: %p\n", &x);
	/* Call fooA() with the address of x */
	fooA(&x);
	/* Print the value of x */
	printf("The value of x: %d\n", x);

	return 0;
}
