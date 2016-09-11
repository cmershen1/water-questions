#include <bits/stdc++.h>
using namespace std;
int main() {
  char a,b;
  scanf("%c%c", &a,&b);
  if(a=='a'||a=='h') {
    if(b=='1'||b=='8')
      printf("3\n");
    else
      printf("5\n");
  }
  else {
    if(b=='1'||b=='8')
      printf("5\n");
    else
      printf("8\n");
  }
}
