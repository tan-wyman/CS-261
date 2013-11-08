#include "bst.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("Guess the animal! (1 for true, anything else is false)\n");
	struct BSTree *tree = buildAnimalTree();
	questionAnimalTree(tree->root);

	return 0;
}
