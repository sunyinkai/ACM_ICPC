A,B,N=map(int,input().strip().split(' '))
f_1,f_2=1,1
for _ in range(N-2):
	f_2,f_1=A*f_2+B*f_1,f_2
	f_2%=7
	f_1%=7
print(f_2)
