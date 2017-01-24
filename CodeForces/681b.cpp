#include <bits/stdc++.h>
using namespace std;


int main() {
  int n,ans=0;
  scanf("%d", &n);
  for(int i=0;i*1234567<=n;i++) {
    for(int j=0;j*123456+i*1234567<=n;j++) {
      if((n-i*1234567-j*123456)%1234==0)
        ans=1;
    }
  }
  if(ans==1)
    printf("YES");
  else
    printf("NO");
}
