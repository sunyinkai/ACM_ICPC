#include<bits/stdc++.h>
using namespace std;

int main(){
	int x=6;
	long long val=(long long)&x;
	cout<<*((int*)val)<<endl;
	return 0;
}
