#include <bits/stdc++.h>
using namespace std;
int main() {
  int m,n;
  char cell[1005][1005];
  int row[1005],col[1005];
  int wall=0;
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++) {
    scanf("%s",cell[i]);
    row[i]=0;
    for(int j=0;j<m;j++)
      if(cell[i][j]=='*') {
        row[i]++;
        wall++;
      }
  }
  for(int j=0;j<m;j++) {
    col[j]=0;
    for(int i=0;i<n;i++) {
      if(cell[i][j]=='*')
        col[j]++;
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      int bombs=row[i]+col[j];
      if(cell[i][j]=='*')
        bombs--;
      if(bombs==wall) {
        printf("YES\n%d %d\n",i+1,j+1);
        return 0;
      }
    }
  }
  printf("NO\n");
}
