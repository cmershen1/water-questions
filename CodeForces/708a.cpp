#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin>>s;
  int flag=0;
  for(int i=0;i<s.length();i++) {
    if(s[i]!='a') {
      s[i]--;
      flag=1;
    }
    else {
      if(flag)
        break;
    }
  }
  if(!flag)
    s[s.length()-1]='z';
  cout<<s<<endl;
}
