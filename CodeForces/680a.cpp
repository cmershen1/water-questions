#include <bits/stdc++.h>
using namespace std;


int main() {
  int a[5],cnt[105],ans=0,m=0;
  memset(cnt,0,sizeof(cnt));
  for(int i=0;i<5;i++) {
    scanf("%d",&a[i]);
    cnt[a[i]]++;
    ans+=a[i];
  }
  for(int i=0;i<5;i++) {
    if(cnt[a[i]]==2) {
      if(a[i]*2>m)
        m=a[i]*2;
    }
    if(cnt[a[i]]>=3) {
      if(a[i]*3>m)
        m=a[i]*3;
    }
  }
  ans=ans-m;
  printf("%d\n", ans);
}
