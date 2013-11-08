/*
File: bst.c
Implementation of the binary search tree data structure.

*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"
#include <string.h>



/*----------------------------------------------------------------------------*/
/*
   function to initialize the binary search tree.
   param tree
pre: tree is not null
post:	tree size is 0
root is null
*/

void initBSTree(struct BSTree *tree)
{
	tree->cnt  = 0;
	tree->root = 0;
}

/*
   function to create a binary search tree.
param: none
pre: none
post: tree->count = 0
tree->root = 0;
*/

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);

	initBSTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
/*
   function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
pre: none
post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
		free(node);
	}
}

/*
   function to clear the nodes of a binary search tree
param: tree    a binary search tree
pre: tree ! = null
post: the nodes of the tree are deallocated
tree->root = 0;
tree->cnt = 0
*/
void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

/*
   function to deallocate a dynamically allocated binary search tree
param: tree   the binary search tree
pre: tree != null;
post: all nodes and the tree structure itself are deallocated.
*/
void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
   function to determine if  a binary search tree is empty.

param: tree    the binary search tree
pre:  tree is not null
*/
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

/*
   function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
/*
   recursive helper function to add a node to the binary search tree.
HINT: You have to use the compare() function to compare values.
param:  cur	the current root node
val	the value to be added to the binary search tree
pre:	val is not null
*/
struct Node *_addNode(struct Node *cur, TYPE val)
{
	/*write this*/
	assert(val != NULL);
	//printf("In _addNode:\nNode is: %p\t val is:%p\n", cur, val);
	if(cur == NULL){
		//printf("tes");
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		assert(newNode != NULL);
		newNode->val = val;
		newNode->left = newNode->right = NULL;
		return newNode;
	}else if(compare(val, cur->val) == (-1)){
		cur->left = _addNode(cur->left, val);
	}else if(compare(val, cur->val) == (1)){
		cur->right = _addNode(cur->right, val);
	}
	return cur;
}

/*
   function to add a value to the binary search tree
param: tree   the binary search tree
val		the value to be added to the tree

pre:	tree is not null
val is not null
pose:  tree size increased by 1
tree now contains the value, val
*/
void addBSTree(struct BSTree *tree, TYPE val)
{
	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}


/*
   function to determine if the binary search tree contains a particular element
HINT: You have to use the compare() function to compare values.
param:	tree	the binary search tree
val		the value to search for in the tree
pre:	tree is not null
val is not null
post:	none
*/

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
	/*write this*/
	assert(tree != NULL);
	struct Node *tmp = tree->root;
	while(tmp != NULL){
		if(compare(val, tmp->val) == (0))
			return (1);
		if(compare(val, tmp->val) == (-1))
			tmp = tmp->left;
		if(compare(val, tmp->val) == (1))
			tmp = tmp->right;
	}
	return 0;
}

/*
   helper function to find the left most child of a node
   return the value of the left most child of cur
param: cur		the current node
pre:	cur is not null
post: none
*/

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	assert(cur != NULL);
	/*write this*/
	while(cur->left != NULL)
		cur = cur->left;
	return cur->val;
}

/*
   helper function to find the right most child of a node
   return the value of the right most child of cur
param: cur		the current node
pre:	cur is not null
post: none
*/

/*----------------------------------------------------------------------------*/
TYPE _rightMost(struct Node *cur)
{
	assert(cur != NULL);
	/*write this*/
	while(cur->right != NULL)
		cur = cur->right;
	return cur->val;
}

/*
   recursive helper function to remove the left most child of a node
HINT: this function returns cur if its left child is NOT NULL. Otherwise,
it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

param: cur	the current node
pre:	cur is not null
post:	the left most node of cur is not in the tree
*/
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
	/*write this*/
	if(cur->left != NULL){
		cur->left = _removeLeftMost(cur->left);
		return cur;
	}else if(cur->right != NULL){
		struct Node *tmp = cur->right;
		free(cur);
		return tmp;
	}else{
		free(cur);
		return NULL;
	}
}

/*
param: cur	the current node
pre:	cur is not null
post:	the right most node of cur is not in the tree
*/
struct Node *_removeRightMost(struct Node *cur)
{
	/*write this*/
	if(cur->right != NULL){
		cur->right = _removeRightMost(cur->right);
		return cur;
	}else if(cur->left != NULL){
		struct Node *tmp = cur->left;
		free(cur);
		return tmp;
	}else{
		free(cur);
		return NULL;
	}
}

/*
   recursive helper function to remove a node from the tree
HINT: You have to use the compare() function to compare values.
param:	cur	the current node
val	the value to be removed from the tree
pre:	val is in the tree
cur is not null
val is not null
*/
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
	/*write this*/
	//printf("In _removeNode:\nNode is: %p\t val is:%p\n", cur, val);
	if(cur == NULL)
		return NULL;
	if(val == NULL)
		return NULL;
	if(compare(val, cur->val) == (0)){
		if(cur->left != NULL){
			cur->val = _rightMost(cur->left);
			cur->left = _removeRightMost(cur->left);
		}else if(cur->right != NULL){
			cur->val = _leftMost(cur->right);
			cur->right = _removeLeftMost(cur->right);
		}else{
			free(cur);
			cur = NULL;
		}
	}else if(compare(val, cur->val) == (-1)){
		cur->left = _removeNode(cur->left, val);
	}else{
		cur->right = _removeNode(cur->right, val);
	}
	return cur;
}
/*
   function to remove a value from the binary search tree
param: tree   the binary search tree
val		the value to be removed from the tree
pre:	tree is not null
val is not null
val is in the tree
pose:	tree size is reduced by 1
*/
void removeBSTree(struct BSTree *tree, TYPE val)
{
	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

/*----------------------------------------------------------------------------*/

/* The following is used only for debugging, set to "#if 0" when used 
   in other applications */
#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
	if (cur == 0) return;
	/*Call print_type which prints the value of the TYPE*/
	print_type(cur->val);
}

void printTree(struct BSTree *tree) {
	if (tree == 0) return;	 
	printNode(tree->root);	 
}
/*----------------------------------------------------------------------------*/

#endif
//extra credit functions
struct BSTree *buildAnimalTree(){
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
/*
void questionAnimalTree(struct Node *cur)
{
	if(cur == NULL)
		return NULL;
	char answer;
	printNode(cur);
	if((cur->left == NULL) && (cur->right == NULL)){
		if(answer == 1){
			printf("The animal is a:\n");
			printNode(cur);
		}else{
			printf("Sorry we don't know your animal.\n");
		}
	}else{
		scanf("%c", &answer);
		if((answer == 1) && (cur->left != NULL)){
			questionAnimalTree(cur->right);
			//cur->right = questionAnimalTree(cur->right);
			//return cur;
			//answer = 0;
		}else if(cur->right != NULL){
			questionAnimalTree(cur->right);
			//cur->left = questionAnimalTree(cur->left);
			//return cur;
			//answer = 0;
		}
	}
	//return cur;
	return;
}
*/

int questionAnimalTree(struct Node *cur)
{
	char answer[5];
	struct Node *tmp = cur;
	printNode(cur);

		

	while(tmp != NULL){
		if((tmp->left == NULL) && (tmp->right == NULL)){
			scanf("%s", answer);
			if(*answer == '1'){
				printf("The animal is a:\n");
				printNode(cur);
				return 1;
			}else{
				printf("Sorry we don't know your animal.\n");
				return 0;
			}
		}else{
			scanf("%s", answer);
			if(*answer == '1'){
				tmp = tmp->left;
			}else{
				tmp = tmp->right;
			}
		}
	}
	return 0;
}



/*
int containsBSTree(struct BSTree *tree, TYPE val)
{
	assert(tree != NULL);
	struct Node *tmp = tree->root;
	while(tmp != NULL){
		if(compare(val, tmp->val) == (0))
			return (1);
		if(compare(val, tmp->val) == (-1))
			tmp = tmp->left;
		if(compare(val, tmp->val) == (1))
			tmp = tmp->right;
	}
	return 0;
}
*/
