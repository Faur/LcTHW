#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 10

typedef enum EyeColor {
	BLUUE_EYES, GREEN_EYES, BROWN_EYES,
	BLACK_EYES, RED_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
	"Blue", "Green", "Brown", "Black", "Red"
};

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eyes;
	float income;
} Person;


int main(int argc, char **argv){
	Person you = {.age = 0};
	int i;
	char *in = NULL;

	printf("What's your First Name? ");
	in = fgets(you.first_name, MAX_DATA-1, stdin);
	// in = fscanf(stdin, "%50s", you.first_name); // BAD BAD BAD!
	check(in, "Failed to read first Name")

	printf("What's your Last Name? ");
	in = fgets(you.last_name, MAX_DATA-1, stdin);
	check(in, "Failed to read last Name? ")

	printf("How old are you? ");
	int rc = fscanf(stdin, "%d", &you.age);
		// Good example of using a pointer as an 'out parameter'
	check(rc > 0, "You have to enter a number.");

	printf("What color are your eyes:\n");
	for(i=0; i <= RED_EYES; i++) printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	printf("> ");
	int eyes;
	rc = fscanf(stdin, "%d", &eyes);
	check(rc > 0, "You have to enter a number.");
	you.eyes = eyes - 1;
	check(you.eyes <= RED_EYES && you.eyes >= 0, "Do it right, that's not an option");

	printf("How much do you make an hour? ");
	rc = fscanf(stdin, "%f", &you.income);
	check(rc > 0, "Enter a floating point number");

	printf("--------------- RESULTS -----------------\n");

	printf("First Name: %s", you.first_name);
	printf("Last Name: %s", you.last_name);
	printf("Age: %d\n", you.age);
	printf("Eyes %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);

	return 0;

error:
	return -1;
}
