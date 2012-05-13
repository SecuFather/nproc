#include "scheduler.h"
#include "util.h"
#include <iostream>

int main(){
	int *task=0;
	//int n = fillTab("19 18 3 18 14 19 4 8", &task);
	//int n = fillTab("26 29 8 1 2 23 24 18", &task);
	//int n = fillTab("72 68 100 11 19 46 51 78 38 61 28 27 89 5 33 69 22 61 30 61", &task);
	int n = fillTab(20, 100, &task);

	TaskManager *tm = new TaskManager(task, n, 6);
	preScheduleForNProc(tm);
	cout << procScheduleToStr(tm);
	cout << "(" << scheduleForNProc(tm) << ")" <<endl;
	cout << procScheduleToStr(tm);

	delete tm;
	delete[] task;
	return 0;
}
