N=int(input())
a,b,mod=0,1,1000000000+7
for i in range(0,N):
	a,b=b,a+b
	a=a%mod
	b=b%mod
print(b)
