#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE in ex22.c available to other .c files
// READ: Global
extern int THE_SIZE;

// gets and sets an internal static vairable in ex22.c
int get_age();
void set_age(int age);

// update a static variable that's insdie update_ratio
double update_ratio(double ration);

void print_size();

#endif