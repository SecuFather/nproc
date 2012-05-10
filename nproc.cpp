#include "scheduler.h"
#include "util.h"
#include <iostream>

int main(){
	int *task=0;
	int n = fillTab("1 5 3 1 4 2 3 2", &task);

	TaskManager *tm = new TaskManager(task, n, 3);
	approxScheduleForNProc(tm);
	cout << procScheduleToStr(tm);

	delete tm;
	delete[] task;
	return 0;
}
