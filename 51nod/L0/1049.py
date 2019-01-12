N=int(input())
ans,now=0,0
while N:
	N=N-1
	x=int(input())
	now+=x
	ans=max(ans,now)
	if now<0:
		now=0
print(ans)
