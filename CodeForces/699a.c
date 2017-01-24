#include <bits/stdc++.h>
int main() {
  int n,i,p=0;
  int d[100005],visited[100005];
  char c[100005];
  memset(visited,0,sizeof(visited));
  scanf("%d", &n);
  scanf("%s", c);
  for(i=0;i<n;i++) {
    scanf("%d",&d[i]);
  }
  while(1) {
    if(p<0 || p>n-1) {
      printf("FINITE\n");
      break;
    }
    else if(visited[p]) {
      printf("INFINITE\n");
      break;
    }
    else {
      visited[p]=1;
      if(c[p]=='>')
        p+=d[p];
      else
        p-=d[p];
    }
  }
  return 0;
}
