#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"
#include <string.h>
#include <string.h>

//yes is -1 because it's less common compared to no(?)
//and -1 is more memory than 1
int compare(TYPE left, TYPE right)
{
    /*FIXME: write this*/
	struct animal *l = (struct animal *)left;
	struct animal *r = (struct animal *)right;
	if(l->truth < r->truth) //yes
		return (-1);
	if(l->truth > r->truth) //no
		return (1);
	if(strcmp(l->statement, r->statement) == 0)
		return (0);
	//if(l->truth == r->truth)
		//return (0);
	return 1;
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
    /*FIXME: write this*/
	struct animal *tmp = (struct animal *)curval;
	printf("%s\n", tmp->statement);
	return;
}


