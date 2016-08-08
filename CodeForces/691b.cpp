#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[1005];
  scanf("%s", s);
  int i=0,j=strlen(s)-1,p=1;
  while(i<j) {
    if(s[i]==s[j]) {
      if(s[i]=='A'||s[i]=='H'||s[i]=='I'||s[i]=='M'||s[i]=='O'||s[i]=='o'||s[i]=='T'||s[i]=='U'||s[i]=='V'||s[i]=='v'||s[i]=='W'||s[i]=='w'||s[i]=='X'||s[i]=='x'||s[i]=='Y') {
        i++;j--;
      } else {
        p=0;break;
      }
    }
    else {//s[i]!=s[j]
      if((s[i]=='b'&&s[j]=='d')||(s[i]=='p'&&s[j]=='q')||(s[i]=='d'&&s[j]=='b')||(s[i]=='q'&&s[j]=='p')) {
        i++;j--;
      }
      else {
        p=0;break;
      }
    }
  }
  if(i==j) {
    if(!(s[i]=='A'||s[i]=='H'||s[i]=='I'||s[i]=='M'||s[i]=='O'||s[i]=='o'||s[i]=='T'||s[i]=='U'||s[i]=='V'||s[i]=='v'||s[i]=='W'||s[i]=='w'||s[i]=='X'||s[i]=='x'||s[i]=='Y')) {
      p=0;
    }
  }
  if(p==0)
    printf("NIE\n");
  else
    printf("TAK\n");
  return 0;
}
