#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[100005];
int capital[100005];
int isCapital[100005];
int main() {
  int n,k,id;
  ll ans=0,sum=0,sumcap=0;
  memset(isCapital,0,sizeof(isCapital));
  scanf("%d %d", &n,&k);
  for(int i=1;i<=n;i++) {
    scanf("%d", &c[i]);
    sum+=c[i];
  }
  for(int i=1;i<=k;i++) {
    scanf("%d", &capital[i]);
    isCapital[capital[i]]=1;
    sumcap+=c[capital[i]];
  }
  for(int i=1;i<=n;i++) {
    if(isCapital[i]) {
      ans+=(sum-c[i])*c[i];
      //cout<<"ans+="<<sum-c[i]<<"*"<<c[i]<<endl;
    }
    else {
      ll temp=sumcap;
      if(i==1) {
        if(!isCapital[2])
          temp+=c[2];
        if(!isCapital[n])
          temp+=c[n];
      }
      else if (i==n) {
        if(!isCapital[1])
          temp+=c[1];
        if(!isCapital[n-1])
          temp+=c[n-1];
      }
      else {
        if(!isCapital[i-1])
          temp+=c[i-1];
        if(!isCapital[i+1])
          temp+=c[i+1];
      }
      ans+=temp*c[i];
      //cout<<"ans+="<<temp<<"*"<<c[i]<<endl;
    }

  }
  ans/=2;
  printf("%I64d\n", ans);
}
