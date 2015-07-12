#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


void die(const char *message) {
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s", message);
	}
	exit (1);
}




// typedef creates a fake type, in this case 
// for a function pointer
typedef int (*compare_cb)(int a, int b);
	//Anything that matches this 'signature' can be put in the place of
	//a compare_cb 
/* A classic bubble sort function that uses the compare_cb
 * to do the sorting
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp) {
	int temp, i, j;
	int *target = malloc(count * sizeof(int));

	if(!target) die("Memory Error.");

	memcpy(target, numbers, count * sizeof(int));




	for(i=0; i<count; i++){
		for(j=0; j<count - 1; j++){
			if(cmp(target[j], target[j+1]) > 0){
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;
}

int sorted_order(int a, int b){
	return a - b;
}

int reverse_order(int a, int b){
	return b - a;
}

int strange_order(int a, int b){
	if (a==0 || b==0) return 0;
	else return a%b;
}








/* Test taht we are testing things correctly
 * by sorting and printing along the way
 */
void test_sorting(int *numbers, int count, compare_cb cmp){
	int i;
	int *sorted = bubble_sort(numbers, count, cmp);

	if(!sorted) die("Failed to sort as requested.");

	for(i=0; i<count; i++){
		printf("%d ", sorted[i]);
	}
	printf("\n");


	free(sorted);
	/*
	unsigned char *data = (unsigned char *)cmp;
	// Output the raw assembler code for the cmp function
	for(i=0; i<25; i++){
		printf("%02x:", data[i]);
	}	printf("\n");
	*/
}


int main (int argc, char **argv) {
	if(argc<2) die("USAGE: ex18 4 3 1 5 6");

	int i;
	int count = argc -1;
	char **inputs = argv+1;

	int *numbers = malloc(count * sizeof(int));
	if(!numbers) puts("ERROR: Memory error.");

	for(i=0; i<count; i++){
		numbers[i] = atoi(inputs[i]);
	}


	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers);

	return 0;
}




