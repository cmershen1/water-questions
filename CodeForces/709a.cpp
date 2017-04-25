#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n,b,d,a,cnt=0;
  ll size=0;
  scanf("%d %d %d", &n,&b,&d);
  for(int i=0;i<n;i++) {
    scanf("%d", &a);
    if(a<=b)
      size+=a;
    if(size>d) {
      size=0;
      cnt++;
    }
  }
  printf("%d", cnt);
}
