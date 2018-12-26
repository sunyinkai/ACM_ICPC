#include <bits/stdc++.h>
using namespace std;
int a[] = {999998, 799998, 599998, 399998, 199998};
//int a[] = {10};
int Rand(int n){
	return (rand() * RAND_MAX + rand()) % n;
}
int main(){
	srand(time(NULL));
	int T = 5;
	printf("%d\n", T);
	for(int ca = 0; ca < T; ca++){
		int n = a[ca], m = 999998, w_max = 3;
		printf("%d %d\n", n, m);
		for(int i = 1; i <= m; i++){
			int u = i % (n - 1) + 2;
			int v = u - Rand(min(10, u-1)) - 1;
			printf("%d %d %d\n", v, u, Rand(3));
		}
	}
	return 0;
}
