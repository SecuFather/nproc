#include "scheduler.h"
#include "util.h"
#include <iostream>

int main(){
	int *task=0;
	//int n = fillTab("19 18 3 18 14 19 4 8", &task);
	//int n = fillTab("26 29 8 1 2 23 24 18", &task);
	int n = fillTab(10, 100, &task);

	TaskManager *tm = new TaskManager(task, n, 3);
	cout << "(" << scheduleForThreeProc(tm) << ")" <<endl;
	cout << procScheduleToStr(tm);

	delete tm;
	delete[] task;
	return 0;
}
