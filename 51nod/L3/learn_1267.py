N=int(input())
result={}
nums=[]
for i in range(N):
    nums.append(int(input()))
for i in range(N):
    for j in range(i+1,N):
        temp=nums[i]+nums[j]
        a=result.get(temp)
        if a!=None:
            for x in a:
                if x[0]!=i and x[1]!=i and x[1]!=j and x[0]!=j:
                    print('Yes')
                    exit()
        if result.get(-temp)==None:
            result[-temp]=[[i,j]]
        else:
            result[-temp].append([i,j])
print('No')
