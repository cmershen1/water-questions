#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,flag=0;
  char ch;
  cin>>n>>m;
  while(n--) {
    int t=m;
    while(t--) {
      cin>>ch;
      if(ch=='C'||ch=='M'||ch=='Y')
        flag=1;
    }
  }
  if(flag==1)
    cout<<"#Color"<<endl;
  else
    cout<<"#Black&White"<<endl;
}
