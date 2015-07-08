#include <stdio.h>

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("ERROR: Program must take ONE argument.\n");
		return 1;
	}

	int i;
	for (i=0; argv[1][i] != '\0'; i++)
	{
		char letter = argv[1][i];

		switch(letter)
		{
			case 'a': //If 'a', jump here, no 'break' so continue to 'A'
			case 'A':
				printf("%2d: 'A'\n", i);
				break;
			case 'e': //fallthrough, a nice indication that this is on purpose
			case 'E':
				printf("%2d: 'E'\n", i);
				break;
			case 'o': //fallthrough
			case 'O':
				printf("%2d: 'O'\n", i);
				break;
			case 'u': //fallthrough
			case 'U':
				printf("%2d: 'U'\n", i);
				break;
			case 'y': //fallthrough
			case 'Y':
				if (i > 2)
				{
					printf("%2d: 'Y'\n",i);
				}
				break;
			default: //ALWAYS have a default
				printf("%2d: %c is not a vowel\n", i, letter);
		}
	}

	return 0;
}


