//dp[i, j] = min{dp[i, k-1]+dp[k, j]}+w[i, j](K[i, j-1]<k<=K[i+1, j])
//先写O(N^3)的代码判断是不是决策单调

//K[i][j-1]<=K[i][j]<=K[i+1][j],打表证明这个东西

for (int i=1;i<=n;i++) {
	K[i][i] = i;
	dp[i][i] = p[i];
	sum[i] = sum[i-1] + p[i];
}

//枚举长度,K[i][j-1]区间长度为L-1为之前算过的
for (int l=2;l<=l;l++) //枚举长度
	for (int i=1;i<=n-l+1;i++) {	//枚举首指针
		int j = i+l-1;	//尾指针
		dp[i][j] = maxw;
		for (int k=K[i][j-1];k<=K[i+1][j];k++)
			if (dp[i][j] > dp[i][k-1]+dp[k][j]) {
				dp[i][j] = dp[i][k-1]+dp[k][j];
				K[i][j] = k;
			}
		dp[i][j] += sum[j]-sum[i-1];//最后加上w[i,j]
	}

//因为要用K[i+1][j],K[i][j-1],故i倒序
//而j需要顺序
for(int i=n;i>=1;--i){ 
	for(int j=i+1;j<=n;++j){ 
		dp[i][j]=maxw;
		for(int k=K[i][j-1];k<=K[i+1][j];++k)
			if(dp[i][j]>dp[i][k-1]+dp[k][j]){ 
				dp[i][j]=dp[i][k-1]+dp[k][j];
				K[i][j]=k;
			}
		dp[i][j]+=sum[j]-sum[i-1];
	}
}

