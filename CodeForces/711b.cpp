#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll a[505][505];
  int n;
  int rx,ry;
  ll rsum[505],csum[505];
  ll rm=0,cm=0;
  memset(rsum,0,sizeof(rsum));
  memset(csum,0,sizeof(csum));
  scanf("%I64d", &n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%d", &a[i][j]);
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      rsum[i]+=a[i][j];
      csum[j]+=a[i][j];
      if(a[i][j]==0) {
        rx=i;ry=j;
      }
    }
  }
  for(int i=0;i<n;i++)
    if(rsum[i]>rm)
      rm=rsum[i];
  a[rx][ry]=rm-rsum[rx];
  rsum[rx]+=a[rx][ry];
  csum[ry]+=a[rx][ry];
  //check
  rm=rsum[0];cm=csum[0];
  int flag=1;
  for(int i=0;i<n;i++) {
    if(rsum[i]!=rm || csum[i]!=rm) {
      flag=0;break;
    }
  }
  ll d1=0,d2=0;
  for(int i=0;i<n;i++) {
    d1+=a[i][i];
    d2+=a[n-1-i][i];
  }
  if(d1!=d2)
    flag=0;
  if(rm!=cm || rm!=d1)
    flag=0;
  if(n==1)
    printf("1\n");
  else if(flag==1 && a[rx][ry]>0)//这里是坑，a[rx][ry]必须是正数
    printf("%I64d\n", a[rx][ry]);
  else
    printf("-1\n");
}
