#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <math.h>

#define E_CONSTANT 2.7182818
#define PI_CONSTANT 3.14159265

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;
	
	returnNum = strtod(s, &end);
	
	/* If there's anything left in end, it's not a number */
	if(strcmp(end, "") == 0) {
		*num = returnNum;
		return 1;
	} else {
		return 0;
	}
}

/*	
 *	name: isE
	pre: the stack contains at least one elements
 *	param: s the string
 *	param: num a pointer to double
 *	returns: void
 *	postcondition: if it is 'e', num will hold 'e'
 *		       constant number
 */
void isE(struct DynArr *stack) 
{
	pushDynArr(stack, E_CONSTANT);
	return;
}

/*	
 *	name: isPi
	pre: the stack contains at least one elements
 *	param: s the string
 *	param: num a pointer to double
 *	returns: void
 *	postcondition: if it is 'pi', num will hold 'pi'
 *		       constant number
 */
void isPi(struct DynArr *stack)
{
	pushDynArr(stack, PI_CONSTANT);
	return;
}


/*	param: stack the stack being manipulated
	pre: the stack contains at least three elements
	post: the top three elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
	//assert(sizeDynArr(stack) >= 3);
	//assert(!isEmptyDynArr(stack));
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE rhs_add = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_add = topDynArr(stack);
	popDynArr(stack);
	TYPE sum = lhs_add + rhs_add;
	pushDynArr(stack, sum);
	return;
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least three elements
	post: the top three elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE rhs_sub = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_sub = topDynArr(stack);
	popDynArr(stack);
	TYPE diff = lhs_sub - rhs_sub;
	pushDynArr(stack, diff);
	return;
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least three elements
	post: the top three elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE rhs_div = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_div = topDynArr(stack);
	popDynArr(stack);
	TYPE quot = lhs_div / rhs_div;
	pushDynArr(stack, quot);
	return;
}

/*
 *	name: multiply
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least three elements
 *	post: the top three elements are popped
 *	post: product is pushed onto the stack
 *	return: void
 */
void multiply(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE rhs_multi = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_multi = topDynArr(stack);
	popDynArr(stack);
	TYPE prod = lhs_multi * rhs_multi;
	pushDynArr(stack, prod);
	return;
}

/*
 *	name: power
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least three elements
 *	post: the top three elements are popped
 *	post: powered value is pushed onto the stack
 *	return: void
 */
void power(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE rhs_pow = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_pow = topDynArr(stack);
	popDynArr(stack);
	TYPE power = pow(lhs_pow, rhs_pow); 
	pushDynArr(stack, power);
	return;
}

/*
 *	name: square
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped
 *	post: squared value is pushed onto the stack
 *	return: void
 */
void square(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_square = topDynArr(stack);
	popDynArr(stack);
	lhs_square = pow(lhs_square, 2); 
	pushDynArr(stack, lhs_square);
	return;
}

/*
 *	name: cube
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped
 *	post: cube value is pushed onto the stack
 *	return: void
 */
void cube(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_cube = topDynArr(stack);
	popDynArr(stack);
	lhs_cube = pow(lhs_cube, 3); 
	pushDynArr(stack, lhs_cube);
	return;
}

/*
 *	name: absoluteVal
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped
 *	post: absolute value is pushed onto the stack
 *	return: void
 */
void absoluteVal(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_abs = topDynArr(stack);
	popDynArr(stack);
	lhs_abs =  abs(lhs_abs);
	pushDynArr(stack, lhs_abs);
	return;
}

/*
 *	name: squareRoot
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped
 *	post: square-root value is pushed onto the stack
 *	return: void
 */
void squareRoot(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_sqrt = topDynArr(stack);
	popDynArr(stack);
	lhs_sqrt = sqrt(lhs_sqrt);
	pushDynArr(stack, lhs_sqrt);
	return;
}

/*
 *	name: exponential
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped
 *	post: "e^x" value is pushed onto the stack
 *	return: void
 */
void exponentional(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_exp = topDynArr(stack);
	popDynArr(stack);
	lhs_exp = pow(E_CONSTANT, lhs_exp);
	pushDynArr(stack, lhs_exp);
	return;
}

/*
 *	name: naturalLog
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped
 *	post: natural log value is pushed onto the stack
 *	return: void
 */
void naturalLog(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_ln = topDynArr(stack);
	popDynArr(stack);
	lhs_ln = log(lhs_ln);
	pushDynArr(stack, lhs_ln);
	return;
}

/*
 *	name: logTen 
 *	param: stack -- stack being manipulated
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped
 *	post: log ten value is pushed onto the stack
 *	return: void
 */
void logTen(struct DynArr *stack)
{
	if(isEmptyDynArr(stack))
		printf("Too few arguements\n");
	TYPE lhs_log = topDynArr(stack);
	popDynArr(stack);
	lhs_log = log10(lhs_log);
	pushDynArr(stack, lhs_log);
	return;
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];
		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			absoluteVal(stack);
		else if(strcmp(s, "sqrt") == 0)
			squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
			exponentional(stack);
		else if(strcmp(s, "ln") == 0)
			naturalLog(stack);
		else if(strcmp(s, "log") == 0)
			logTen(stack);
		else if(strcmp(s, "e") == 0)
			isE(stack);
		else if(strcmp(s, "pi") == 0)
			isPi(stack);
		else if(isNumber(s, &result)){
			pushDynArr(stack, result);
		} else {
			printf("Invalid Arguement\n");
		}
	}	//end for 

// Hint: General algorithm:
// (1) Check if the string s is in the list of operators.
//   (1a) If it is, perform corresponding operations.
//   (1b) Otherwise, check if s is a number.
//     (1b - I) If s is not a number, produce an error.
//     (1b - II) If s is a number, push it onto the stack

// FIXME: You need to develop the code here (when s is not an operator)
// Remember to deal with special values ("pi" and "e")
/* FIXME: You will write this part of the function (2 steps below) 
* (1) Check if everything looks OK and produce an error if needed.
* (2) Store the final value in result and print it out.
*/
	result = topDynArr(stack);	
	popDynArr(stack);
	if(!isEmptyDynArr(stack)){
		printf("Invalid number of arguements.\n");
	//} else {
	//	printf("The result is %g\n", result);
	}
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;
	double tmp = calculate(argc,argv);
	printf("The result is %g\n", tmp);
	return 0;
}
