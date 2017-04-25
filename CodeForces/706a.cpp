#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  scanf("%d %d", &a, &b);
  int n;
  scanf("%d", &n);
  double x,y,v,ans=1e300;
  while(n--) {
    scanf("%lf %lf %lf", &x,&y,&v);
    double t=sqrt((x-a)*(x-a)+(y-b)*(y-b))/v;
    if(t<ans)
      ans=t;
  }
  printf("%lf\n", ans);
}
