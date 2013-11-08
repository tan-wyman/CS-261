#ifndef ctype.h
#include <ctype.h>
#endif

int truth(TYPE statement)
{
	struct animal *q = (struct animal *);
	char answer[5];
	char yes[5] = {'y', 'e', 's', '\n'};
	//char no[5] = {'n', 'o', '\n'};
	answer = scanf("%s");
	printf("Your answer was: %s\n", &answer);
	tolower(answer);
	return (if(strcmp(answer, yes) == 0));
}
	


