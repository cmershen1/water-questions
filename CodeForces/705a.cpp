#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if(n==1)
    cout<<"I hate it"<<endl;
  else {
    for(int i=1;i<=n;i++) {
      if(i%2)
        cout<<"I hate ";
      else
        cout<<"I love ";
      if(i==n)
        cout<<"it"<<endl;
      else
        cout<<"that ";
    }
  }
}
