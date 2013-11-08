#include <assert.h>
#include <string.h>
#include "animal.h"
#include "structs.h"
#include "bst.h"
#include "bst.c"


struct BSTree* buildAnimalTree(){
	struct BSTree *tree = newBSTree();

	struct animal *animal1 = (struct animal *)malloc(sizeof(struct animal));
	struct animal *animal2 = (struct animal *)malloc(sizeof(struct animal));
	struct animal *animal3 = (struct animal *)malloc(sizeof(struct animal));
	struct animal *animal4 = (struct animal *)malloc(sizeof(struct animal));
	struct animal *animal5 = (struct animal *)malloc(sizeof(struct animal));
	struct animal *animal6 = (struct animal *)malloc(sizeof(struct animal));
	struct animal *animal7 = (struct animal *)malloc(sizeof(struct animal));

	animal1->truth = 0;
	animal1->statement = "Lives in water?";
	animal2->truth = -1;
	animal2->statement = "Mammal?";
	animal3->truth = 1;
	animal3->statement = "Climb trees?";
	animal4->truth = -1;
	animal4->statement = "Whale?";
	animal5->truth = 1;
	animal5->statement = "Sea Turtle?";
	animal6->truth = -1;
	animal6->statement = "Cat?";
	animal7->truth = 1;
	animal7->statement = "Dog?";

	addBSTree(tree, animal1);
	addBSTree(tree, animal2);
	addBSTree(tree, animal3);
	addBSTree(tree, animal4);
	addBSTree(tree, animal5);
	addBSTree(tree, animal6);
	addBSTree(tree, animal7);

	return tree;
}
//-1 is yes, 1 is no
struct Node *questionAnimalTree(struct Node *cur)
{
	assert(cur != NULL);
	char answer[5];
	char yes[5] = {'y', 'e', 's', '\n'};
	print_type(cur);
//	printf("%s\n", cur->statement);
	scanf("%s", answer);
	if((cur->left == NULL) && (cur->right == NULL)){
		if(strcmp(answer, yes) == 0){
		//	printf("The animal is: %s\n", cur->statement);
			printNode(cur);
		}else{
			printf("Sorry we don't know your animal.\n");
		}
	}else{
		if((strcmp(answer, yes) == 0) && (cur->left != NULL)){
			cur->left = questionAnimalTree(cur->left);	
		}else if(cur->right != NULL){
			cur->right = questionAnimalTree(cur->right);
		}
	}
	return cur;


		
}

/*
 * if NULL and NULL //at a leaf
 *	yes: print congratz
 *	no: print sorry
 *	return node
 * else //question
 *	if yes: cur->left = recur
 *	if no: cur->right = recur
 *
 * return cur;
 */
