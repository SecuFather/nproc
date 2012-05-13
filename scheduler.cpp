#include "scheduler.h"

int findDeviation(TaskManager *tm){
	int max=-1, nproc = tm->procCount();
	int n = tm->taskCount();
	int *res = new int[nproc];

	memset(res, 0, sizeof(int)*nproc);
	tm->resetIterator();
	for(int i=0; i<n; ++i){
		if(tm->completee(i) < 0){
			res[tm->taskProc(i)+1] += tm->taskValue(i);
		}
	}
	for(int i=0; i<nproc; ++i){
		if(res[i] > max){
			max = res[i];
		}
	}

	delete[] res;
	return max - tm->cmaxx();
}

int preScheduleForNProc(TaskManager *tm){
	int cmax = tm->cmaxx();
	int nproc = tm->procCount();
	int *tab = new int[cmax+1];
	int it, task, v, x;

	for(int k=0; k<nproc-1; ++k){
		memset(tab, -1, sizeof(int)*(cmax+1));
		tab[0] = 0;

		tm->resetIterator();
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
		while(tab[--it] < 0);
		while(it > 0){
			tm->setUsed(tab[it], k);
			it -= tm->taskValue(tab[it]);
		}
	}

	delete[] tab;
	return findDeviation(tm);
}

int scheduleForNProc(TaskManager *tm){
	tm->setAllUnused();
	int dev0 = preScheduleForNProc(tm);
	int nproc = tm->procCount();
	if(!dev0 || nproc < 3){
		return 0;
	}
	int dev = dev0;
	int cmax = tm->cmaxx();
	int sum = tm->summ();
	int n = tm->taskCount();
	int size = (nproc-1) * tm->cmaxx() + 1;
	int at, min, pos, task, v, x;
	int *solved = new int[n];
	list<int> *tab = new list<int>[size];
	list<int>::iterator *it = new list<int>::iterator[size];
	list<int>::iterator ti;
	stack<int> stos;
	tab[0].push_back(0);
	tm->fillSolved(solved);


	tm->fillSolved(solved);
	tm->setAllUnused();
	min = dev;
	tm->resetIterator();
	while((task = tm->nextTask()) >= 0){
		v = tm->taskValue(task);
		for(int i=size-1; i>=v; --i){
			x = i-v;
			if(!tab[x].empty()){
				tab[i].push_back(task);
			}
		}
	}

	for(int i=0; i<size; ++i){
		it[i] = tab[i].begin();
	}
	pos = size;
	do{
		at = pos;
		while(--at > 0 && tab[at].empty());
		pos = at;
		if(sum-at-cmax > min){
			break;
		}
		while(at > 0){
			if(it[at] != tab[at].end()){
				task = *(it[at]);
				if(tm->taskProc(task) < 0){
					tm->setUsed(task, 0);
					x = tm->taskValue(task);
					at -= x;
					stos.push(x);
				}else{
					++(it[at]);
				}
			}else{
				if(stos.empty()){
					break;
				}
				it[at] = tab[at].begin();
				at += stos.top();
				stos.pop();
				++it[at];
			}
		}
		for(int i=0; i<n; ++i){
			if(tm->taskProc(i) < 0){
				tm->setComplete(i, nproc-2);
			}
		}
		while(!stos.empty()){
			it[stos.top()] = tab[stos.top()].begin();
			stos.pop();
		}
		tm->changeNproc(-1);
		dev = scheduleForNProc(tm);
		x = sum-pos-cmax;
		dev = (dev > x ? dev : x);
		if(dev < min){
			tm->fillSolved(solved);
			min  = dev;
		}
		tm->changeNproc(1);
		tm->setAllUncomplete();
		tm->setAllUnused();
	}while(min != 0);

	tm->saveSolved(solved);
	delete[] it;
	delete[] tab;
	delete[] solved;
	cout << dev0-min << endl;
	return min;
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
