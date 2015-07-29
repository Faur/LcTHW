#undef NDEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>

/* 
 * Naive copy that assumes all inputs are always valid
 * Taken from K&R and cleaned up a bil.
 */

void copy(char *to, char *from) {
	int i = 0;

	//while loop will not end if from isn't '\0' terminated
	while((to[i] = from[i]) != '\0') ++i;
}

 /*
  * A safer version that checks for many common errors using the
  * length of each string to control the loops and termination
  */
int safer_copy(int from_len, char *from, int to_len, char *to){
	assert(from != NULL && to != NULL && "from and to can't be NULL");
		// If this fails the OS typically prints the assert line
		// including the message
	if(from_len < 0 || to_len <= 0) return -1;
		// to must have atleast one byte
	
	int i;
	int max = from_len > to_len - 1 ? to_len - 1 : from_len;
	for(i = 0; i < max; i++) to[i] = from[i];

	to[to_len -1] = '\0';

	return i;
}

int main(int argc, char **argv){
	char from[] = "0123456789";
	int from_len = sizeof(from);

	char to[] = "0123456";
	int to_len = sizeof(to);

	debug("Copying '%s':%d to '%s':%d", from, from_len, to, to_len);

	int rc = safer_copy(from_len, from, to_len, to);
	check(rc > 0, "Failed to safer_copy");
	check(to[to_len-1] == '\0', "String not terminated");

	debug("Result is: '%s:%d", to, to_len);

	rc = safer_copy(from_len * -1, from, to_len, to);
	check(rc > 0, "Failed to safer_copy");
	check(to[to_len-1] == '\0', "String not terminated");

	rc = safer_copy(from_len, from, 0, to);
	check(rc > 0, "Failed to safer_copy");
	check(to[to_len-1] == '\0', "String not terminated");

	return 0;

error:
	return 1;
}











