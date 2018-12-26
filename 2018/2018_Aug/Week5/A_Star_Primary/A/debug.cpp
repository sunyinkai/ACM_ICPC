#include<cstdio>
#include<cstring>
#include<list>
using namespace std;
int main(){
	list<int>ls[2];
	ls[0].push_back(1);ls[0].push_back(2);
	ls[1].push_back(3);ls[1].push_back(4);
	ls[0].splice(ls[0].end(),ls[1]);
	printf("%d %d\n",ls[0].size(),ls[1].size());
	return 0;
}
