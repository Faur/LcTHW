// Interesting string copy from
// http://www.joelonsoftware.com/articles/CollegeAdvice.html

#include <stdio.h>
#include <string.h>
#define LEN 10

int main(){
	char t[LEN];
	memset(t, 'x', LEN);
	t[LEN-1] = '\0';

	char s[LEN];
	memset(s, 'y', LEN);
	s[LEN-1] = '\0';

	char *ss = s;
	char *tt = t;

	printf("%p %p", s, ss);
	puts("");

	printf("%s\n%s\n", t, s);
	puts("");
	while((*ss++ = *tt++));
	printf("%s\n%s\n", t, s);

	return 0;
}