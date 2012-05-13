#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "taskmanager.h"
#include <sstream>
#include <stack>
#include <iostream>
using namespace std;

//returns max deviation
int findDeviation(TaskManager *tm);

//pre schedule tasks and returns max deviation
int preScheduleForNProc(TaskManager *tm);

//schedule tasks for two processors
int scheduleForNProc(TaskManager *tm);

//returns string describing proc schedule
string procScheduleToStr(TaskManager *tm);


#endif /* SCHEDULER_H_ */
