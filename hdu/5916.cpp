#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,k;
int main() {
  scanf("%d",&T);
  for(int i=1;i<=T;i++) {
    scanf("%d %d",&n,&k);
    printf("Case #%d: %d %d ",i,2*k,k);
    for(int j=k+1;j<=2*k-1;j++)
      printf("%d ", j);
    for(int j=2*k+1;j<=n;j++)
      printf("%d ", j);
    for(int j=1;j<k-1;j++)
      printf("%d ", j);
    if(k>1)
      printf("%d", k-1);
    printf("\n");
  }
}
