#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t0,t,n;
int a[100005];
int cost(int x) {
    queue<int> q1,q2;
    int ans=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
        q1.push(a[i]);
    if((n-1)%(x-1)!=0) {
        int temp=(n-1)%(x-1)+1;
        int sum=0;
        for(int j=0;j<temp;j++) {
            sum+=q1.front();
            q1.pop();
        }
        q2.push(sum);
        ans+=sum;
    }
    while(!q1.empty()) {
        int sum=0;
        for(int j=0;j<x;j++) {
            if(!q1.empty() && !q2.empty()) {
                if(q1.front()<q2.front()) {
                    sum+=q1.front();
                    q1.pop();
                }
                else {
                    sum+=q2.front();
                    q2.pop();
                }
            }
            else if(q1.empty()) {
                sum+=q2.front();
                q2.pop();
            }
            else if(q2.empty()) {
                sum+=q1.front();
                q1.pop();
            }
        }
        ans+=sum;
        q2.push(sum);
    }
    while(q2.size()>1) {
        int sum=0;
        for(int i=0;i<x;i++) {
            ans+=q2.front();
            q2.pop();
        }
        ans+=sum;
        q2.push(ans);
    }
    return ans;
}
int main() {
    scanf("%d",&t0);
    while(t0--) {
        scanf("%d %d",&n,&t);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        int l=2,r=n;
        while(l<r) {
            int mid=(l+r)/2;
            if(cost(mid)<=t)
                r=mid;
            else
                l=mid+1;
        }
        printf("%d\n", l);
    }
}
