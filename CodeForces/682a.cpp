#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n,m;ll ans=0;
  scanf("%d %d",&n,&m);
  for(int i=5;i<=n+m;i+=5) {
    int t=i-1;
    if(i-1>m)
      t-=i-m-1;
    if(i-1>n)
      t-=i-n-1;
    //cout<<i<<","<<t<<endl;
    ans+=t;
  }
  printf("%I64d\n", ans);
}
