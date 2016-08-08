#include <bits/stdc++.h>
using namespace std;


int main() {
  int n,a,d,t[105],ans=0;
  scanf("%d %d", &n,&a);
  for(int i=1;i<=n;i++)
    scanf("%d", &t[i]);
  for(int i=1;i<=n;i++) {
    if(t[i]) { //这个位置有罪犯
      if(i<a) {
        d=a-i;
        if(a+d<=n && t[a+d]) //两边都有，就都能抓到
          ans+=1;
        else if(a+d>n)  //这个距离只能在一边存在
          ans+=1;
      }
      else if(i>a) {
        d=i-a;
        if(a-d>=1 && t[a-d])
          ans+=1;
        else if(a-d<1)
          ans+=1;
      }
      else //i==a
        ans+=1;
    }
  }
  printf("%d\n", ans);
}
