#include "scheduler.h"

int approxScheduleForNProc(TaskManager *tm){
	int cmax = tm->cmaxx();
	int nproc = tm->procCount();
	int *tab = new int[cmax+1];
	int dev, it, max=-1, task, v, x;

	for(int k=0; k<nproc-1; ++k){
		memset(tab, -1, sizeof(int)*(cmax+1));
		tab[0] = 0;

		while((task = tm->nextTask()) >= 0 && tab[cmax] < 0){
			v = tm->taskValue(task);
			for(int i=cmax; i>=v; --i){
				x = i-v;
				if(tab[i] < 0 && tab[x] >= 0){
					tab[i] = task;
				}
			}
		}

		it=cmax+1;
		dev = 0;
		while(tab[--it] < 0 && it > 0 && ++dev);
		while(it>0){
			tm->setUsed(tab[it], k);
			it -= tm->taskValue(tab[it]);
		}
		max = (dev > max ? dev : max);
	}

	delete[] tab;
	return max;
}

string procScheduleToStr(TaskManager *tm){
	stringstream out;
	int n = tm->taskCount();
	int nproc = tm->procCount();
	int *result = new int[nproc];
	int at, v;
	stringstream *row = new stringstream[nproc];

	memset(result, 0, sizeof(int)*nproc);

	for(int i=0; i<n; ++i){
		at = tm->taskProc(i)+1;
		v = tm->taskValue(i);
		result[at] += v;
		row[at] << "+" << v;
	}
	for(int i=0; i<nproc; ++i){
		row[i] << "=" << result[i];
		out << row[i].str() << endl;
	}

	delete[] row;
	delete[] result;
	return out.str();
}
