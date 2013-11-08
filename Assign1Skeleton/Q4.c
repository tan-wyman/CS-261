/* CS 261 - Assignment 1 - Q4
 * Name: Wyman Tan
 * Date: 4-10-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENT 10

struct student {
	int id;
	int score;
};

void sort(struct student *students, int n) {
	/* Sort the n students based on their score */     
	/* Remember, each student must be matched with their original score after sorting */
	int tmp_id = 0;
	int tmp_score = 0;
	while(n > 0){
		for(int i = 1; i < n; ++i){
			if((students + i)->id < (students + i - 1)->id){
				/*studend id swaps*/
				tmp_id = (students + i)->id;
				(students + i)->id = (students + i - 1)->id;
				(students + i - 1)->id = tmp_id;
				/*student score swaps*/
				tmp_score = (students + i)->score;
				(students + i)->score = 
					(students + i - 1)->score;
				(students + i - 1)->score = tmp_score;
			}
		}
		--n;
	}
}

struct student* allocate(int n) {
	/* Allocate memory for ten students */
	struct student *p = 
		(struct student*)(malloc(n * sizeof(struct student)));

	/* Return the pointer */
	return p;
}

void generate(struct student *students, int n) {
	/* Generate random IDs and scores for 10 students */
	/* The ID should be between 1 and 20, scores between 0 and 100 */
	srand(time(NULL));
	for(int i = 0; i < n; ++i){
		(students + i)->id = (rand() % 20 + 1);
		(students + i)->score = (rand() % 101);
		for(int j = 0; j < i; ++j){
			while(((students + i)->id == (students + j)->id) 
					&& (i != j)){
				(students + i)->id = (rand() % 20 + 1);
			}
		}
	}
	return;
}

void output(struct student *students, int n){
	for(int i = 0; i < n; ++i){
		printf("ID%d \t %d\n",
				(students + i)->id,
				(students + i)->score); 
	}
	return;
}

void summary(struct student *students, int n) {
	int min = students->score;
	int max = students->score;
	double avg = 0;
	for(int i = 0; i < n; ++i){
		if(((students + i)->score) > max)
			max = (students + i)->score;
		if(((students + i)->score) < min)
			min = (students + i)->score;
		avg += (students + i)->score;
	}
	avg /= n;
	printf( "Minimum score: %d\n"
			"Maximim score: %d\n"
			"Average score: %g\n",
			min, max, avg);
	return;
}

void deallocate(struct student *stud) {
	if(stud != NULL)
		free(stud);
	return;
}
int main() {
	struct student *stud = NULL;
	/* Declare an integer n and assign it a value */
	int n = NUM_STUDENT;
	/* Allocate memory for n students using malloc */
	stud = allocate(n); 
	/* Generate random IDs and scores for the n students, using rand() */
	generate(stud, n); 
	/* Print the contents of the array of n students */
	printf("Unsorted:\n");
	output(stud, n);
	/* Pass this array along with n to the sort() function */
	sort(stud, n); 
	/* Print the contents of the array of n students */
	printf("Sorted:\n");
	output(stud, n);

	return 0;
}
