#include<cstdio>
int main(){
	int cow,car,show;
	while(~scanf("%d%d%d",&cow,&car,&show)){
		int sum=car+cow;
		double xcar=car*1.0/sum;//换之前选到牛或车的概率
		double xcow=cow*1.0/sum;
		xcar*=(cow-show)*1.0/(sum-show-1);
		xcow*=(cow-show-1)*1.0/(sum-show-1);
		printf("%.5f\n",1-xcar-xcow);
	}
	return 0;
}
