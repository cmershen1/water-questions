#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int grid[310][310];
int t[31];
int n;
bool vis[310][310][31][9];
void dfs(int x,int y,int dep,int dir) {
    if(vis[x][y][dep][dir])
        return;
    if(dep==n+1 || x<1 || x>300 || y<1 || y>300)
        return;
    vis[x][y][dep][dir]=true;
    switch(dir)  {
    case 1://UP
        for(int i=0;i<t[dep];i++) {
            if(y+i <= 300)
                grid[x][y+i]=1;
        }
        
        dfs(x+1, y+t[dep], dep+1, 2);
        dfs(x-1, y+t[dep], dep+1, 8);
        break;
    case 2://RIGHT-UP
        for (int i = 0; i < t[dep]; i++) {
            if(x+i<=300 && y+i<=300)
                grid[x+i][y+i]=1;
        }
        dfs(x+t[dep]-1, y+t[dep], dep+1, 1);
        dfs(x+t[dep], y+t[dep]-1, dep+1, 3);
        break;
    case 3://RIGHT
        for (int i = 0; i < t[dep]; i++) {
            if(x+i<=300)
                grid[x+i][y]=1;
        }
        dfs(x+t[dep], y+1, dep+1, 2);
        dfs(x+t[dep], y-1, dep+1, 4);
        break;
    case 4://RIGHT-DOWN
        for (int i = 0; i < t[dep]; i++) {
            if(x+i<=300 && y-i>=1)
                grid[x+i][y-i]=1;
        }
        dfs(x+t[dep], y-t[dep]+1, dep+1, 3);
        dfs(x+t[dep]-1, y-t[dep], dep+1, 5);
        break;
    case 5://DOWN
        for (int i = 0; i < t[dep]; i++) {
            if(y-i>=1)
                grid[x][y-i]=1;
        }
        dfs(x+1, y-t[dep], dep+1, 4);
        dfs(x-1, y-t[dep], dep+1, 6);
        break;
    case 6://LEFT-DOWN
        for (int i = 0; i < t[dep]; i++) {
            if(x-i>=1 && y-i>=1)
                grid[x-i][y-i]=1;
        }
        dfs(x-t[dep]+1, y-t[dep], dep+1, 5);
        dfs(x-t[dep], y-t[dep]+1, dep+1, 7);
        break;
    case 7://LEFT
        for (int i = 0; i < t[dep]; i++) {
            if(x-i>=1)
                grid[x-i][y]=1;
        }
        dfs(x-t[dep], y-1, dep+1, 6);
        dfs(x-t[dep], y+1, dep+1, 8);
        break;
    case 8://LEFT-UP
        for (int i = 0; i < t[dep]; i++) {
            if(x-i>=1 && y+i<=300)
                grid[x-i][y+i]=1;
        }
        dfs(x-t[dep]+1, y+t[dep], dep+1, 1);
        dfs(x-t[dep], y+t[dep]-1, dep+1, 7);
        break;
    }   
}

int main() {
    while(cin>>n) {
	    for (int i = 1;i <= n; i++) {
	        cin>>t[i];
	    }
        memset(grid,0,sizeof(grid));
        memset(vis,0,sizeof(vis));
	    dfs(150,150,1,1);
	    int cnt=0;
	    for (int i = 1; i <= 300; i++) {
	        for (int j = 1; j <= 300; j++) {
	            if(grid[i][j]==1)
	                cnt++;
	        }
	    }
	    cout<<cnt<<endl;
    }
}

