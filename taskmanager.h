#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <list>
#include <cstring>
using namespace std;

class TaskManager{
private:
	int *task, *used;
	int cmax, it, margin, n, nproc, sum;

	//returns sum of elements
	int sumElements(int *ar, int n);
public:
	TaskManager(int *task, int n, int nproc);
	~TaskManager();

	//returns index of next task, if it does not exist, returns -1
	int nextTask();

	//returns task value
	inline int taskValue(int at)const{ return task[at]; }

	//sets task as used at given proc
	inline void setUsed(int at, int proc){ used[at] = proc; }

	//sets all tasks unused
	inline void setAllUnused(){ memset(used, -1, sizeof(int)*n); }

	//returns cmax
	inline int cmaxx()const{ return cmax; }

	//returns proc id for task
	inline int taskProc(int at)const{ return used[at]; }

	//returns task count
	inline int taskCount()const{ return n; }

	//returns proc count
	inline int procCount()const{ return nproc; }
};


#endif /* TASKMANAGER_H_ */
