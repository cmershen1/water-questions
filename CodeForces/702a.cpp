#include <bits/stdc++.h>
using namespace std;

int a[100005];
int main() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    scanf("%d", &a[i]);

  int ans=1;
  int len=1;
  for(int i=1;i<n;i++) {
    if(a[i]>a[i-1]){
      len++;
      if(len>ans)
        ans=len;
    }
    else
      len=1;

    //cout<<len<<' '<<ans<<endl;
  }
  printf("%d\n", ans);
}
