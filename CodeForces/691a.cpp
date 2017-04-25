#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,a,total=0;
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    cin>>a;
    total+=a;
  }

  if((n==1 && total==1) || (n>1 && total==n-1))
    printf("YES\n");
  else
    printf("NO");
}
