#include "scheduler.h"
#include "util.h"
#include <iostream>

int main(){
	int *task=0;
	int n = fillTab("1 5 5 25 28 23 14 7 3 4 7", &task);

	TaskManager *tm = new TaskManager(task, n, 4);
	cout << "(" << preScheduleForNProc(tm) << ")" << endl;
	cout << procScheduleToStr(tm);

	delete tm;
	delete[] task;
	return 0;
}
