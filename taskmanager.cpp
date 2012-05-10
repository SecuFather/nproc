#include "taskmanager.h"

TaskManager::TaskManager(int *task, int n, int nproc) :
	task(new int[n]), used(new int[n]), it(-1), n(n), nproc(nproc)
{
	setAllUnused();
	memcpy(this->task, task, sizeof(int)*n);

	sum = sumElements(task, n);
	margin = (sum % nproc != 0);
	cmax = sum / nproc + margin;
}

TaskManager::~TaskManager(){
	delete[] used;
	delete[] task;
}

int TaskManager::sumElements(int *ar, int n){
	int sum=0;
	for(int i=0; i<n; ++i){
		sum += ar[i];
	}
	return sum;
}

int TaskManager::nextTask(){
	while(++it < n){
		if(used[it] < 0){
			return it;
		}
	}
	return it = -1;
}
