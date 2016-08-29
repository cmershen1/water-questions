#include <bits/stdc++.h>
using namespace std;
int x[100005];
int main() {
  int n,q;
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    scanf("%d", &x[i]);
  sort(x,x+n);
  scanf("%d", &q);
  int m;
  while(q--) {
    scanf("%d", &m);
    printf("%d\n", upper_bound(x,x+n,m)-x);
  }
}
