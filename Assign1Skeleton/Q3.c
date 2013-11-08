/* CS 261 - Assignment 1 - Q3
 * Name: Wyman Tan
 * Date: 4-10-13
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sort(int *numbers, int n) {
	/* Sort the array numbers, of length n */     
	int tmp = 0;
	while(n > 0){
		for(int i = 1; i < n; ++i){
			if(*(numbers + i) < *(numbers + i - 1)){
				tmp = *(numbers + i);
				*(numbers + i) = *(numbers + i - 1);
				*(numbers + i - 1) = tmp;
			}
		}
		--n;
	}
}

int main() {
	/* Declare an integer n and assign it a value of 20 */
	int n = 20;
	/* Allocate memory for an array of n integers using malloc */
	int *array = malloc(n * sizeof(int));
	/* Fill this array with random numbers, using rand() */
	srand(time(NULL));
	for(int i = 0; i < n; ++i)
		*(array + i) = rand() % 101;
	/* Print the contents of the array */
	printf("\nUnsorted:\n");
	for(int j = 0; j < n; ++j) printf("%d\n", *(array + j));
	/* Pass this array along with n to the sort() function of part a */
	sort(array, n);
	/* Print the contents of the array */    
	printf("\nSorted:\n");
	for(int j = 0; j < n; ++j)
		printf("%d\n", *(array + j));

	return 0;
}
