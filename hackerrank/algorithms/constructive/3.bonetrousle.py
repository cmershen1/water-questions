t=input()
for tt in range(t):
    n,k,b = map(int,raw_input().split())
    if b*(b+1)/2>n or (2*k-b+1)*b/2<n:
        print (-1)
    else:
        ans=range(0,b+1)
        diff=n-b*(b+1)/2
        p=b
        a=k
        while diff>0:
            if diff<=a-ans[p]:
                ans[p]+=diff
                diff=0
            else:
                diff-=a-ans[p]
                ans[p]=a
                p-=1
                a-=1
        #print ans
        for i in range(1,b,1):
                print ans[i],
        print ans[b]
