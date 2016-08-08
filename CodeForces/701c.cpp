#include <bits/stdc++.h>
using namespace std;
char s[100005];
int m[260];
int main() {
  int n,ans,types=0;
  scanf("%d", &n);
  scanf("%s", s);
  memset(m,0,sizeof(m));

  ans=n;
  for(int i=0;i<n;i++) {
    m[s[i]]++;
    if(m[s[i]]==1)
      types++;
  }
  memset(m,0,sizeof(m));
  m[s[0]]=1;
  int i=0,j=0, cnt=1;
  while(j<n) {
    while(cnt<types) {
      cout<<i<<' '<<j<<' '<<cnt<<endl;
      j++;
      if(j==n)
        break;
      if(m[s[j]]==0) {
        cnt++;
      }
      m[s[j]]++;
    }
    while(cnt==types) {
      cout<<i<<' '<<j<<' '<<cnt<<endl;
      m[s[i]]--;
      if(m[s[i]]==0) {
        if(j-i+1<ans)
          ans=j-i+1;
        cnt--;
      }
      i++;
    }

  }

  printf("%d\n",ans);
}
