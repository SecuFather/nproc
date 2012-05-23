#ifndef UTIL_H_
#define UTIL_H_

#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;;

class StopWatch{
private:
	timeval a, b;
	long sec, usec, t;
public:
	//starts stopwatch
	inline void start(){ gettimeofday(&a, 0); }

	//stops stopwatch and returns result in ms
	int stop();
};

//returns elements count, allocate memory for tab and fills it with numbers
int fillTab(const char* str, int **tab);

//returns elements count, allocate memory for tab and fills it with random numbers
int fillTab(int n, int maxValue, int **tab);

#endif /* UTIL_H_ */
