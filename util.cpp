#include "util.h"

int fillTab(const char* str, int **tab){
	stringstream ss;
	string temp;
	stack<int> s;
	int n;
	ss << str;

	while(getline(ss, temp, ' ')){
		s.push(atoi(temp.c_str()));
	}
	n = s.size();
	tab[0] = new int[n];

	for(int i=0; !s.empty(); ++i){
		tab[0][i] = s.top();
		s.pop();
	}
	return n;
}

int fillTab(int n, int maxValue, int **tab){
	srand(time(0));
	tab[0] = new int[n];

	for(int i=0; i<n; ++i){
		tab[0][i] = rand() % maxValue + 1;
	}
	return n;
}
