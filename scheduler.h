#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "taskmanager.h"
#include <sstream>

//returns max deviation
int findDeviation(TaskManager *tm);

//pre schedule tasks and returns max deviation
int preScheduleForNProc(TaskManager *tm);

//returns string describing proc schedule
string procScheduleToStr(TaskManager *tm);


#endif /* SCHEDULER_H_ */
