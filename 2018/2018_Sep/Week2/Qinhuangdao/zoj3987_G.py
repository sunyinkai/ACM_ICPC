T=int(raw_input().strip())
for case in range(T):
	a,b=map(int,raw_input().strip().split())
	if a==0:
		print "0"
		continue
	if a<=b:
		print "1"
		continue
	ans1=a/b;
	ans2=ans1
	if a%b!=0:
		ans2=ans1+1
	print ans2|ans1
