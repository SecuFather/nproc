#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <list>
#include <cstring>
using namespace std;

class TaskManager{
private:
	int *complete, *task, *used;
	int cmax, it, margin, n, nproc, sum;

	//returns sum of elements
	int sumElements(int *ar, int n);

	//returns cmax
	int findMax(int *ar, int n);
public:
	TaskManager(int *task, int n, int nproc);
	~TaskManager();

	//returns index of next task, if it does not exist, returns -1
	int nextTask();

	//returns task value
	inline int taskValue(int at)const{ return task[at]; }

	//sets task used at given proc
	inline void setUsed(int at, int proc){ used[at] = proc; }

	//sets all tasks unused
	inline void setAllUnused(){ memset(used, -1, sizeof(int)*n); }

	//returns cmax
	inline int cmaxx()const{ return cmax ; }

	//returns proc id for task
	inline int taskProc(int at)const{ return used[at]; }

	//returns task count
	inline int taskCount()const{ return n; }

	//returns proc count
	inline int procCount()const{ return nproc; }

	//resets iterator
	inline void resetIterator(){ it = -1; }

	//returns margin
	inline int marginn()const{ return margin; }

	//returns sum of all elements
	inline int summ()const{ return sum; }

	//returns completness
	inline int completee(int at)const{ return complete[at]; }

	//sets task complete at given proc
	inline void setComplete(int at, int proc){ complete[at] = proc; }

	//sets all task uncomplete
	inline void setAllUncomplete(){ for(int i=0; i<n; ++i)if(complete[i] < nproc-1)complete[i]= -1; }

	//change nproc with change param
	inline void changeNproc(int change){ nproc += change; }

	//fills solved array
	inline void fillSolved(int *ar){ for(int i=0; i<n; ++i)ar[i] = (complete[i]<0 ? used[i] : complete[i]); }

	//bla bla
	inline void saveSolved(int *ar){ memcpy(used, ar, sizeof(int)*n); }
};


#endif /* TASKMANAGER_H_ */
