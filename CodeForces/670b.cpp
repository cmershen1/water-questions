#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll k;
int id[100005];
ll getl(ll k) {
    //这里顺序查找会超时，要二分答案
    ll l=1,r=1e5;
    while(l<r) {
        ll mid=(l+r)/2;
        //cout<<'['<<l<<','<<r<<']'<<endl;
        if(mid*(mid-1)/2 < k && mid*(mid+1)/2 >=k)
            return mid;
        else if(mid*(mid-1)/2>=k)
            r=mid;
        else
            l=mid+1;
    }
    return -1;
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d",&id[i]);
    }
    int l=getl(k);
    //cout<<l<<endl;
     printf("%d\n", id[k-l*(l-1)/2-1]);
}
