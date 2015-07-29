#include "ex22.h"
#include "dbg.h"
// Alternative to #define
const char *MY_NAME = "Toke <The Nickname> Faurby";

void scope_demo(int count) {

	log_info("count is: %d", count);

	if(count > 10) {
		int count = 100; // BAD! BUGGY!

		log_info("Count in this scope is %d", count);
	}

	log_info("Count is at exit: %d", count);

	count = 3000;

	log_info("count after assignment: %d", count);
}

long long int recursive(long long int i){
	printf("%lld\n", i);
	return recursive(++i);
}

int main(int argc, char **argv) {
	// test: THE_AGE accessor
	log_info("My name: %s, age: %d.", MY_NAME, get_age());

	set_age(370);
	log_info("My age is now: %d", get_age());

	//TEST: THE_SIZE extern
	puts("");
	log_info("THE_SIZE is: %d", THE_SIZE);
	print_size();

	THE_SIZE = 9;

	log_info("THE_SIZE is now: %d", THE_SIZE);
	print_size();


	//TEST: ratio function static
	puts("");
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio agian: %f", update_ratio(10.00));
	log_info("Ratio one more: %f", update_ratio(300.0));

	//TEST: scope demo
	puts("");
	int count = 4;
	scope_demo(count);
	scope_demo(count*20);

	log_info("count after calling scope_demo: %d", count);

	return 0;
}
