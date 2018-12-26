#include <iostream>
#include<cstdio>
using namespace std;

int prime[20];
//f(m,n):从1-m中不被前n个质数整除的个数
int phi(int x, int n) {//计算[1,m]内与p互素的个数,特判p=1的情况
    if (n == 0) return x - x / prime[0];
    return phi(x, n - 1) - phi(x / prime[n], n - 1);
}

int main() {
	//计算1-x内与p互素的数的个数
	int x, p;
	scanf("%d%d", &x, &p);
	if (p == 1) {//judge
		printf("%d",x);
		return 0;
	}
	int tot = 0;
	for (int i = 2; i * i <= p; i++) {
		if (p % i == 0) {
			prime[tot++] = i;
			while (p % i == 0) p /= i;
		}
	}
	if (p > 1) prime[tot++] = p;
	tot--;
	printf("%d\n",phi(x,tot));
    return 0;
}
