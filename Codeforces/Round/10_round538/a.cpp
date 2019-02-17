#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z;
	int a,b,c;
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	bool isok=true;
	a-=x;
	if(a<0)isok=false;
	b+=a;
	b-=y;
	if(b<0)isok=false;
	c+=b;
	c-=z;
	if(c<0)isok=false;

	printf(isok?"YES\n":"NO\n");
	return 0;
}
