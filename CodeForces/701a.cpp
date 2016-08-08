#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[105],visited[105];
  memset(visited,0,sizeof(visited));
  int n,sum=0;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) {
    scanf("%d", &a[i]);
    sum+=a[i];
  }
  sum=sum*2/n;//每个人得到的点数为sum
//  cout<<sum<<endl;
  for(int i=1;i<=n;i++) {
    for(int j=i+1;j<=n;j++) {
      if(!visited[i] && !visited[j] && a[i]+a[j]==sum) {
        visited[i]=1;visited[j]=1;//发过的牌不能再发
        printf("%d %d\n", i,j);
      }
    }
  }

}
