#include<cstdio>
#include<cstring>
int main(){
	int w,h,n;
	scanf("%d%d%d",&w,&h,&n);
	int lx=0,ly=0,rx=w,ry=h;
	
	for(int i=0;i<n;++i){
		char s[3];scanf("%s",s);
		int H;scanf("%d",&H);
		if(s[0]=='H'){
			if(H>=ry||H<=ly){

			}else{
				if(H>=(ly+ry)/2){//上半部分
					ry=H;
				}else{
					ly=H;
				}
			}
		}else{
			if(H<=lx||H>=rx){
			
			}else{
				if(H>=(lx+rx)/2){//右半部分
					lx=H;
				}else{
					rx=H;
				}
			}
		}
	//	printf("(%d,%d) (%d,%d)\n",lx,ly,rx,ry);
		printf("%lld\n",(long long)(rx-lx)*(ry-ly));
	}
	return 0;
}
