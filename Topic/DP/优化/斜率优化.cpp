int left=1,right=1;
	q[1]=0;
	f[0]=0;
	for(int i=1;i<=n;++i){
		while(left<right&&slope(q[left],q[left+1])<=sumd[i])left++;
		//维护队首,删除非最优决策
		int front=q[left];
		f[i]=calc(i,front);
		//维护队尾,既下凸包性质
		while(left<right&&slope(q[right-1],q[right])>=slope(q[right],i))right--
		q[++right]=i;
	}
