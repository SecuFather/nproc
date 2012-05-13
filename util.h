#ifndef UTIL_H_
#define UTIL_H_

#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;;


//returns elements count, allocate memory for tab and fills it with numbers
int fillTab(const char* str, int **tab);

//returns elements count, allocate memory for tab and fills it with random numbers
int fillTab(int n, int maxValue, int **tab);

#endif /* UTIL_H_ */
