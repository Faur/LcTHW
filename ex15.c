#include <stdio.h>

int main(int argc, char *argv[])
{
	//create two arrays
	int ages [] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank", 
		"Mary", "John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages)/sizeof(ages[0]);
	int i = 0;

	printf("first way: using indexing\n");
	for(i=0; i<count; i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}
	printf("---\n");

	printf("seccond way: pointers to start of array\n");
	int *cur_age = ages; 
	char **cur_name = names;

	//The loop
	for (i=0; i<count; i++)
	{
		printf("%s is %d years old\n", *(cur_name+i), *(cur_age+i));
	}

	printf("---\n");

	printf("third way: pointers are just arrays\n");
	for(i=0; i<count; i++) 
	{
		printf("%s is %d years old.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	printf("fourth way: stupid complex pointers\n");
	for(; //cur_name=names, cur_age=ages 
		(cur_age - ages)< count; //Q: WHY DOES THIS WORK??
								// A: Because there is 1 difference in addres for each element
		(cur_name++, cur_age++))
	{
		printf("%ld: %s is %d years atm.\n",
			(cur_age - ages), *cur_name, *cur_age);
	}

	return 0;
}



