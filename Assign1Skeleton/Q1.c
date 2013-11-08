/* CS 261 - Assignment 1 - Q1
 * Name: Wyman Tan <tanw>
 * Date: 4-8-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/* Allocate memory for ten students */
	struct student *p = 
		(struct student*)(malloc(10 * sizeof(struct student)));

	/* Return the pointer */
	return p;
}

void generate(struct student *students) {
	/* Generate random IDs and scores for 10 students */
	/* The ID should be between 1 and 20, scores between 0 and 100 */
	srand(time(NULL));
	for(int i = 0; i < 10; ++i){
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

void output(struct student *students) {
	/* Output information about the ten students in the format:
	   ID1 score1
	   ID2 score2
	   ID3 score3
	   ...
	   ID10 score10 */
	for(int i = 0; i < 10; ++i){
		printf("ID%d \t %d\n",
				(students + i)->id,
				(students + i)->score); 

	}
	return;
}

void summary(struct student *students) {
	/* Compute and print the minimum, maximum, and average scores of the ten students */
	int min = students->score;
	int max = students->score;
	double avg = 0;
	for(int i = 0; i < 10; ++i){
		if(((students + i)->score) > max)
			max = (students + i)->score;
		if(((students + i)->score) < min)
			min = (students + i)->score;
		avg += (students + i)->score;
	}
	avg /= 10;
	printf( "Minimum score: %d\n"
			"Maximim score: %d\n"
			"Average score: %g\n",
			min, max, avg);
	return;
}

void deallocate(struct student *stud) {
	/* Deallocate memory from stud */
	if(stud != NULL)
		free(stud);
	return;
}

int main(int argc, char **argv) {
	struct student *stud = NULL;
	/* Call allocate */
	stud = allocate();
	/* Call generate */
	generate(stud); 
	/* Call output */
	output(stud); 
	/* Call summary */
	summary(stud); 
	/* Call deallocate */
	deallocate(stud);

	return 0;
}
