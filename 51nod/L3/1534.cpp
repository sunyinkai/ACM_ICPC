#include <bits/stdc++.h>
using namespace std;
int main(){
	int xa,xb,ya,yb;
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    if(xa <= xb && ya <= yb) printf("Polycarp\n");
    else if(xa > xb && ya > yb) printf("Vasiliy\n");
    else{
        if(xa+ya <= max(yb,xb)) printf("Polycarp\n");
        else printf("Vasiliy\n");
    }
    return 0;
}
 
