n=int(raw_input().strip())
d=map(int,raw_input().strip().split(' '))
x=d[:]
x.sort()

l=0
r=0
for i in range(n):
    if x[i]!=d[i]:
        l=i
        break

for i in range(n-1,0,-1):
    if x[i]!=d[i]:
        r=i
        break

if l!=r:
    x[l],x[r]=x[r],x[l]
    if x==d:
        print ('yes')
        print ('swap '+str(l+1)+' '+str(r+1))
    else:
        x.sort()
        x[l:r+1]=x[l:r+1][::-1]
        if x==d:
            print ('yes')
            print ('reverse '+str(l+1)+' '+str(r+1))
        else:
            print ('no')
else:
    print ('no')
