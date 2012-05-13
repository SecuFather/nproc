#include "taskmanager.h"

TaskManager::TaskManager(int *task, int n, int nproc) :
	complete(new int[n]), task(new int[n]), used(new int[n]), it(-1), n(n), nproc(nproc)
{
	int tmp;

	setAllUnused();
	memcpy(this->task, task, sizeof(int)*n);
	memset(complete, -1, sizeof(int)*n);

	sum = sumElements(task, n);
	margin = (sum % nproc != 0);
	cmax = sum / nproc + margin;
	if((tmp = findMax(task, n)) > cmax){
		cmax = tmp;
	}

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

int TaskManager::findMax(int *ar, int n){
	int max=-1;
	for(int i=0; i<n; ++i){
		if(ar[i] > max){
			max = ar[i];
		}
	}
	return max;
}

int TaskManager::nextTask(){
	while(++it < n){
		if(used[it] < 0 && complete[it] < 0){
			return it;
		}
	}
	return it = -1;
}
