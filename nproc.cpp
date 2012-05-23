#include "scheduler.h"
#include "util.h"
#include <iostream>

//argv[0] name of application
//argv[1] ammount proccessors
//argv[2] ammount tasks
//argv[3] range of tasks' time
//argv[4] ammount of test
int main(int argc, char **argv){
	int *task=0;
	int n = atoi(argv[2]);
	int nproc = atoi(argv[1]);
	int range = atoi(argv[3]);
	int sum=0;
	int testCount = atoi(argv[4]);

	for(int i=0; i<testCount; ++i){
		fillTab(n, range, &task);

		TaskManager *tm = new TaskManager(task, n, nproc);
		StopWatch sw;
		sw.start();
		scheduleForNProc(tm);
		sum += sw.stop();

		delete tm;
		delete[] task;
	}
	cout << sum/testCount << endl;
	return 0;
}
