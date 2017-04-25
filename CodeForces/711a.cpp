#include <bits/stdc++.h>
using namespace std;
char a[1005][5];
int main() {
  int n,flag=0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    cin>>a[i];
  for (int i = 0; i < n; i++)  {
    if(flag==0) {
      if(a[i][0]=='O' && a[i][1]=='O') {
        flag=1;
        a[i][0]='+';a[i][1]='+';
        break;
      }
      else if(a[i][3]=='O' && a[i][4]=='O') {
        flag=1;
        a[i][3]='+';a[i][4]='+';
        break;
      }
    }
  }
  if(flag==0) {
    printf("NO\n");
  }
  else {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      for(int j=0;j<4;j++)
        cout<<a[i][j];
      cout<<a[i][4]<<endl;
    }
  }
}
