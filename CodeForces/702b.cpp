#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int binarySearch(int t,int start,int end) {
  int *lb=lower_bound(a+start,a+end,t);
  int *ub=upper_bound(a+start,a+end,t);
  //cout<<ub<<' '<<lb<<' '<<t<<endl;
  return ub-lb;
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    scanf("%d", &a[i]);
  ll ans=0;
  sort(a,a+n);
  for(int i=0;i<n;i++) {
    for(int j=0;j<31;j++) {
      int t=(1<<j)-a[i];
      if(t>=a[i] && t<=a[n-1]) {
        ans+=binarySearch(t,i+1,n);
      }
    }
  }

  printf("%I64d\n", ans);
}
