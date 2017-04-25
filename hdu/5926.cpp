//source:2016CCPC东北地区大学生程序设计竞赛 - 重现赛
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
int grid[32][32];
void solve(int c) {
    bool flag=true;
    for(int i=0;i<m;i++) {
        for(int j=i+1;j<m;j++) {
            if(grid[0][i]==grid[0][j])
                flag=false;
            if(grid[n-1][i]==grid[n-1][j])
                flag=false;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(grid[i][0]==grid[j][0])
                flag=false;
            if(grid[i][m-1]==grid[j][m-1])
                flag=false;
        }
    }
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<m-1;j++) {
            if(grid[i][j]==grid[i][j+1])
                flag=false;
            if(grid[i][j]==grid[i+1][j])
                flag=false;
        }
    }
    if(flag)
        printf("Case #%d: No\n",c);
    else
        printf("Case #%d: Yes\n",c);
}
int main() {
    scanf("%d",&t);
    for(int c=1;c<=t;c++) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&grid[i][j]);
        solve(c);
    }
}
