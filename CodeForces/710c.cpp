#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int l=-(n-1)/2,r=(n-1)/2;
  int odd=1,even=2;
  for(int i=l;i<=r;i++) {
    for(int j=l;j<=r;j++) {
      if(abs(i)+abs(j)>(n-1)/2) {
        printf("%d", even);
        even+=2;
        if(j==r)
          printf("\n");
        else
          printf(" ");
      }
      else {
        printf("%d", odd);
        odd+=2;
        if(j==r)
          printf("\n");
        else
          printf(" ");
      }
    }
  }
}
