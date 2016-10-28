//source:2016CCPC东北地区大学生程序设计竞赛 - 重现赛
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IN(s) freopen(s,"r",stdin)
#define OUT(s) freopen(s,"w",stdout)
int t,n,x,ans,cnt;
int q[400010];
char op[10];
set<int> s;
int main() {
  //IN("5929.in");
  scanf("%d",&t);
  int ca=1;
  while(t--) {
    printf("Case #%d:\n", ca++);
    scanf("%d",&n);
    int l=200005,r=200006;//双端对列从中点开始
    s.clear();
    bool d=0;//0 for left,1 for right
    while(n--) {
      scanf("%s",op);
      if(op[0]=='P' && op[1]=='U') { //PUSH x
        scanf("%d",&x);
        if(d==0) {
          q[l]=x;
          if(x==0)
            s.insert(l);
          l--;
        }
        else {
          q[r]=x;
          if(x==0)
            s.insert(r);
          r++;
        }
      }
      else if(op[0]=='P' && op[1]=='O') { //POP
        if(d==0) {
          if(q[l+1]==0)
            s.erase(l+1);
          l++;
        }
        else {
          if(q[r-1]==0)
            s.erase(r-1);
          r--;
        }
      }
      else if(op[0]=='Q') { //QUERY
        if(r-l<=1)
          printf("Invalid.\n");
        else {
          if(s.empty())
            printf("%d\n", (r-l+1)&1);
          else {
            set<int>::iterator i = s.last();
            //i--;
           //printf("Debug: begin=%d,end=%d,l=%d,r=%d,d=%d\n",*s.begin(),*i,l,r,d);
            if(d==0) {
              if(*i-l>1)
                printf("%d\n",(r-*i)&1);
              else
                printf("%d\n", (r-*i+1)&1);
            }
            else {
              if(r-*s.begin()>1)
                printf("%d\n",(*s.begin()-l)&1);
              else
                printf("%d\n",(*s.begin()-1-l)&1);
            }
          }
        }
      }
      else //REVERSE
        d=!d;
    }
  }
}
