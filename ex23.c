#include <stdio.h>
#include <string.h>
#include "dbg.h"

#include <time.h>

int normal_copy(char *from, char*to, int count) {
	int i;

	for(i=0; i<count; i++){
		to[i] = from[i];
	}

	return i;
}

int duffs_device(char *from, char*to, int count) {
	{
		int n = (count + 7)/8;

		switch(count % 8) {
			case 0: do{ *to++ = *from++;
						case 7: *to++ = *from++;
						case 6: *to++ = *from++;
						case 5: *to++ = *from++;
						case 4: *to++ = *from++;
						case 3: *to++ = *from++;
						case 2: *to++ = *from++;
						case 1: *to++ = *from++;
					} while(--n > 0);
		}
	}

	return count;
}

int zeds_device(char *from, char *to, int count){
	/* This is an example of manual loop unrolling.
	 * Modern compilers are capable of this as well, 
	 * so this should only be done if you can prove
	 * that it is more efficient.
	 */
	{

		int n = (count % 6 == 0) ? count/6 : count/6 + 1;
			//int n = (count + 5) / 6; // equivelent statement 

		switch(count % 6 ) {
			case 0:
			again: *to++ = *from++;
//			case 7: *to++ = *from++;
//			case 6: *to++ = *from++;
			case 5: *to++ = *from++;
			case 4: *to++ = *from++;
			case 3: *to++ = *from++;
			case 2: *to++ = *from++;
			case 1: *to++ = *from++;
					if(--n >0) goto again;
		}
	}

	return count;
}


int valid_copy(char *data, int count, char expects){
	int i;
	for(i = 0; i < count; i++) {
		if(data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}

	return 1;
}

#define LEN 1000
int main(int argc, char **argv){
	char from[LEN] = {'a'};
	char to[LEN] = {'c'};
	int rc = 0;

	//setup the from to have some stuff
	memset(from, 'x', LEN);
	memset(to, 'y', LEN);
	check(valid_copy(to, LEN, 'y'), "Not initialized right.");

	//USE: normal copy
	puts("Norm");
//	clock_t t0 = clock();
	memset(to, 'y', LEN);
	rc = normal_copy(from, to, LEN);
	check(rc == LEN, "Normal copy failed: %d.", rc);
	check(valid_copy(to, LEN, 'x'), "Normal copy failed.");

//	long double t_elapsed = (clock() - t0)/CLOCKS_PER_SEC;
//	printf("Time elapsed, Norm: %Le\n", t_elapsed);

	/*Reset*/	
	memset(to, 'y', LEN);
	//duffs version
	puts("Duff");
	rc = duffs_device(from, to, LEN);
	check(rc == LEN, "Duff's device failed: %d.", rc);
	check(valid_copy(to, LEN, 'x'), "Duff's device failed.");

	/*Reset*/	
	memset(to, 'y', LEN);
	//Zeds version
	puts("Zed");
	rc = zeds_device(from, to, LEN);
	check(rc == LEN, "Zed's device failed: %d.", rc);
	check(valid_copy(to, LEN, 'x'), "Zed's deice failed.");

	
	puts("Toke");
	memset(to, 'y', LEN);
	//Tokes version
	rc = 0;
	{
		char *to2 = to;
		char *from2 = from;
		while((*to2++ = *from2++), rc++<LEN-1);
	}
	check(rc == LEN, "Toke's device failed: %d.", rc);
	check(valid_copy(to, LEN, 'x'), "Toke's device failed.");
	/**/

	return 0;

error:
	return 1;

}





