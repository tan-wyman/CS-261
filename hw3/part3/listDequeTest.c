#include "cirListDeque.h"
#include <stdio.h>

int main(){
	struct cirListDeque* q = createCirListDeque(); 
	addBackCirListDeque(q, (TYPE)1);
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printCirListDeque(q);
	printf("\n");
	//6, 5, 4, 1, 2, 3
	printf("%g\n", frontCirListDeque(q));
	printf("\n");
	//6
	printf("%g\n", backCirListDeque(q));
	printf("\n");
	//3
	removeFrontCirListDeque(q);
	//5, 4, 1, 2, 3
	removeBackCirListDeque(q);
	//5, 4, 1, 2
	printCirListDeque(q);
	printf("\n");
	//5, 4, 1, 2
	reverseCirListDeque(q);
	//2, 1, 4, 5
	printCirListDeque(q);
	printf("\n");
	//2, 1, 4, 5
	deleteCirListDeque(q);
	return 0;
}
