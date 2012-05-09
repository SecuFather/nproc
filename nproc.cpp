#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int compare(const void *a, const void *b){ return (*(int*)a - *(int*)b); }

void scheduleForNProc(int *task, int n, int nproc){
	int *tab, sum=0, cmax, t, tsk;
	int *used;

	for(int i=0; i<n; ++i){
		sum += task[i];
	}
	cmax = sum/nproc+(sum%nproc != 0);
	tab = new int[cmax+1];
	used = new int[n];
	memset(used, 0, sizeof(int)*n);

	for(int k=0; k<nproc-1; ++k){
		memset(tab, 0, sizeof(int)*(cmax+1));
		for(int i=0; i<n; ++i){
			if(!used[i]){
				tsk = task[i];
				for(int j=cmax; j>=tsk; --j){
					t = j-tsk;
					if(!tab[j]){
						if(t>=0 && t<=cmax && tab[t]){
							tab[j] = i+1;
						}else{
							if(j == tsk){
								tab[j] = i+1;
							}
						}
					}
				}
			}
		}
		sum=0;
		for(int i=cmax; i>0;){
			if(tab[i]){
				t = task[tab[i]-1];
				sum += t;
				printf("+%d", t);
				used[tab[i]-1] = 1;
				i -= t;
			}else{
				--i;
			}
		}
		printf("=%d\n", sum);
	}
	sum = 0;
	for(int i=0; i<n; ++i){
		if(!used[i]){
			sum += (t = task[i]);
			printf("+%d", t);
		}
	}
	printf("=%d\n", sum);
	delete[] used;
	delete[] tab;
}

int main(){
	srand(time(0));
	int n = 6;
	int *t = new int[n];
	for(int i=0; i<n; ++i){
		t[i] = rand()%(n*n)+1;
	}
	qsort(t, n, sizeof(int), compare);

	for(int i=0; i<n; ++i){
		printf("%d ", t[i]);
	}
	printf("\n");

	scheduleForNProc(t, n, 3);

	delete[] t;
	return 0;
}
void scheduleForTwoProac(int *task, int n){
	int *tab, sum=0, cmax, t, tsk;
	int *used;

	for(int i=0; i<n; ++i){
		sum += task[i];
	}
	cmax = sum/2;
	tab = new int[cmax+1];
	used = new int[n];
	memset(used, 0, sizeof(int)*n);
	memset(tab, 0, sizeof(int)*(cmax+1));

	for(int i=0; i<n; ++i){
		tsk = task[i];
		for(int j=cmax; j>=tsk; --j){
			t = j-tsk;
			if(!tab[j]){
				if(t>=0 && t<=cmax && tab[t]){
					tab[j] = i+1;
				}else{
					if(j == tsk){
						tab[j] = i+1;
					}
				}
			}
		}
	}
	for(int i=0; i<cmax; ++i){
		printf("%d ", tab[i]);
	}
	printf("\n");
	sum=0;
	for(int i=cmax; i>0;){
		if(tab[i]){
			t = task[tab[i]-1];
			sum += t;
			printf("+%d", t);
			used[tab[i]-1] = 1;
			i -= t;
		}else{
			--i;
		}
	}
	printf("=%d\n", sum);
	sum = 0;
	for(int i=0; i<n; ++i){
		if(!used[i]){
			sum += (t = task[i]);
			printf("+%d", t);
		}
	}
	printf("=%d\n", sum);
	delete[] used;
	delete[] tab;
}
