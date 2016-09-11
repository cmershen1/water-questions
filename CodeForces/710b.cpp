#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[300005];
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    scanf("%d", &x[i]);
  sort(x,x+n);
  printf("%d\n", x[(n-1)/2]);
}
