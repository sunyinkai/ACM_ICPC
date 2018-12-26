#include<stdio.h>
int main(){
    int n, s=0
    scanf("%d", &n);
    while (n){
        s+=n/5;
        n/=5;
    }
    printf("%d", s);
    return 0;
}
