/* CS 261 - Assignment 1 - Q5
 * Name: Wyman Tan
 * Date: 4-10-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Converts a lower case letter to upper case */
char toUpperCase(char ch) {
	return ch - 'a' + 'A';
}

/* Converts an upper case letter to lower case */
char toLowerCase(char ch) {
	return ch - 'A' + 'a';
}

void sticky(char *word) {
	/* Convert to sticky caps */
	for(int i = 0; i < sizeof(word); ++i){
		if(i % 2 == 0){
			*(word + i) = toupper(*(word + i));
		}else{
			*(word + i) = tolower(*(word + i));
		}
	}
}

int main() {
	/* Read word from the keyboard using scanf */
	char word[100];
	printf("Input text string:\n");
	scanf("%s", word);
	/* Call sticky */
	sticky(word);
	/* Print the new word */
	printf("Sticky caps conversion: \n%s\n", word);

	return 0;
}
