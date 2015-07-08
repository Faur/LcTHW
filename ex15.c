#include <stdio.h>

//void print_1 (int ages[], char *names[]) 
void print_1 (int count, int *ages, char **names) 
{
	int i;
	printf("first way: using indexing\n");
	for(i=count-1; i>=0; i--)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}
}

void print_2 (int count, int *ages, char**names)
{
	printf("seccond way: pointers to start of array\n");
	int i;
	for (i=count; i>0; i--)
	{
		printf("%s is %d years old\n", *(names+count-i), *(ages+count-i));
	}
}

void print_3 (int count, int *ages, char **names)
{
	printf("third way: pointers are just arrays\n");
	int i; 
	for(i=count; i>0; i--) 
	{
		printf("%s is %d years old.\n", names[count-i], ages[count-i]);
	}
}

void print_4(int count, int *ages, char **names)
{ 
	printf("fith way: stupid complex pointers reversed\n");
	int *cur_age = ages; 
	char **cur_name = names; 
	for(cur_name=names+count-1, cur_age=ages+count-1	; 
		(cur_age - ages) >= 0; //Q: WHY DOES THIS WORK??
								// A: Because there is 1 difference in addres for each element
		(cur_name--, cur_age--))
	{
		printf("%ld: %s is %d years atm.\n",
			(cur_age - ages), *cur_name, *cur_age);
	}
}

int main(int argc, char *argv[])
{
	//create two arrays
	int ages [] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank", 
		"Mary", "John", "Lisa"
	};
	// SAFELY GET THE SIZE OF THE INT ARRAY
	int count = sizeof(ages)/sizeof(ages[0]);

	print_1(count, ages, names);
	printf("---\n");

	print_2(count, ages, names);
	printf("---\n");

	print_3(count, ages, names);
	printf("---\n");

	print_4(count, ages, names);
	return 0;
}


