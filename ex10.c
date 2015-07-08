#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("argc: %d\n", argc);
	int i = -1;

	/*
	Go through each string in argv
	Q: Why is argv[0] skipped?
	*/
	for (; i++, i<argc;){
		printf("arg %d: %s\n", i, argv[i]);
	}
	argv[0] = "";
	for (i = 0;i<argc; i++){
		printf("arg %d: %s\n", i, argv[i]);
	}


	char *s = argv[1];
	argv[1] = "new String";
	printf("s: %s\n", s);

	return 0;
}