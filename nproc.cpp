#include "scheduler.h"
#include "util.h"
#include <iostream>

int main(){
	int *task=0;
	//int n = fillTab("19 18 3 18 14 19 4 8", &task);
	//int n = fillTab("26 29 8 1 2 23 24 18", &task);
	//int n = fillTab("72 68 100 11 19 46 51 78 38 61 28 27 89 5 33 69 22 61 30 61", &task);
	//int n = fillTab("87 94 83 88 73 4 72 22 68 7 61 7 28 86 85 90 52 29 64 55 52 61 58 52 97 10 2 62 78 93 34 58 68 2 9 95 3 73 97 26 48 99 66 6 41 89 41 92 68 9 2 84 80 7 93 9 69 86 6 60 19 18 63 7 83 95 38 38 100 20 22 29 78 92 99 12 4 54 97 54", &task);
	//int n = fillTab("78 94 93 38 47 52 7 2 15 99 96 96", &task);
	//int n = fillTab("85 82 6 63 6 89 35 44 30 55 24 4 55 15 51 15 97 44 17 6 80 84 8 33 57 30 36 37 78 49 87 60 17 35 81 25 23 85 12 6 61 3 69 29 63 1 98 65 90 68 5 49 66 41", &task);
	int n = fillTab(54, 100, &task);

	TaskManager *tm = new TaskManager(task, n, 15);
	cout << "(" << preScheduleForNProc(tm) << ")" << endl;
	cout << procScheduleToStr(tm);
	cout << "(" << scheduleForNProc(tm) << ")" <<endl;
	cout << procScheduleToStr(tm);

	delete tm;
	delete[] task;
	return 0;
}
