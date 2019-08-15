#define PCRE2_CODE_UNIT_WIDTH 8

#include <stdio.h>
#include <string.h>
#include <pcre2.h>
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
uint line_count = 1;
uint match_count = 0;
bool matches=false;
char *word="Ship";

// pcre2 init
pcre2_code *re;
int reti;
PCRE2_SPTR pattern;      /* PCRE2_SPTR is a pointer to unsigned code units of */
pattern = (PCRE2_SPTR)word;
pcre2_match_data *match_data;
int errornumber;
PCRE2_SIZE erroroffset;

// compile engine RegEx from given Pattern :
re = pcre2_compile(
  pattern,               /* the pattern */
  PCRE2_ZERO_TERMINATED, /* indicates pattern is zero-terminated */
  0,                     /* default options */
  &errornumber,          /* for error number */
  &erroroffset,          /* for error offset */
  NULL);                 /* use default compile context */

// Test validity of compiled RegEx:
if (re == NULL)
  {
  PCRE2_UCHAR buffer[256];
  pcre2_get_error_message(errornumber, buffer, sizeof(buffer));
  printf("PCRE2 compilation failed at offset %d: %s\n", (int)erroroffset,
    buffer);
  return EXIT_FAILURE;
  }

// RegEx match testing against lines:
while ((read = getline(&line, &len, fp)) != -1) {
	// Test match
	match_data = pcre2_match_data_create_from_pattern(re, NULL);
	reti = pcre2_match(
	  re,                   /* the compiled pattern */
	  (PCRE2_SPTR)line,     /* the subject string */
	  read,                 /* the length of the subject */
	  0,                    /* start at offset 0 in the subject */
	  0,                    /* default options */
	  match_data,           /* block for storing the result */
	  NULL                  /* use default match context */
	);

	// on match
	if (reti>0) {
		match_count++;
		printf("Match in Line: %d\n", line_count);
		if (!matches)
			matches=true;
		printf("%s\n", line);
	}

	line_count++;
}

// Print summery:
if (!matches)
	printf("Sorry, no matches!\n");
else
	printf("%d matches.\n", match_count);

// Clean up:
fclose(fp);
if (line)
	free(line);

pcre2_match_data_free(match_data);
pcre2_code_free(re);

return EXIT_SUCCESS;

}
