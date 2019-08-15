#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <regex.h>
#include <stdbool.h>

#define uint unsigned int

// Read file
// test RegEx match line-wise in a loop

int main(void)
{

// File init and open
FILE *fp;
char *line = NULL;
size_t len = 0;
ssize_t read;

fp = fopen("rime.txt", "r");
// file with no matches:
// fp = fopen("test.txt", "r");
if (fp == NULL)
	return EXIT_FAILURE;

// misc init
char msgbuf[100];
uint line_count = 1;
uint match_count = 0;
bool matches=false;

// posix_re init
regex_t regex;
int reti;

// compile engine RegEx from given Pattern :
reti = regcomp(&regex, "Ship", 0);

// Test validity of compiled RegEx:
if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    return EXIT_FAILURE;
}


// RegEx match testing against lines:
while ((read = getline(&line, &len, fp)) != -1) {
	// Test match
	reti = regexec(&regex, line, 0, NULL, 0);

	// on match
	if (!reti) {
		printf("Match in Line: %d\n", line_count);
		match_count++;
		if (!matches)
			matches=true;
		printf("%s\n", line);
	}
	line_count++;
	
}

if (!matches)
	printf("Sorry, no matches!\n");
else
	printf("%d matches.\n", match_count);

fclose(fp);
if (line)
	free(line);

return EXIT_SUCCESS;
}

