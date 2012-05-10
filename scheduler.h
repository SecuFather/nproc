#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "taskmanager.h"
#include <sstream>


//returns max deviation from optimum
int approxScheduleForNProc(TaskManager *tm);

//returns string describing proc schedule
string procScheduleToStr(TaskManager *tm);


#endif /* SCHEDULER_H_ */
