#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
vector<int> g1[2222],g2[2222];
bool vis1[2222],vis2[2222];
int T,n;
char c;
bool bfs(int u,vector<int> g[]) {
    bool* vis;
    if(g==g1)
        vis=vis1;
    else
        vis=vis2;
    queue<int> q;
    int d[2222];
    q.push(u); vis[u]=true; d[u]=1;
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        if(d[v]==3) return false;
        for(int i=0;i<g[v].size();i++) {
            int next=g[v][i];
            if(!vis[next]) {
                d[next]=d[v]+1;
                vis[next]=true;
                q.push(next);
            }
        }
    }
    return true;
}

int main() {
    // RE("in.txt");
    // WR("out.txt");
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)  {
            g1[i].clear();
            g2[i].clear();
            vis1[i]=vis2[i]=false;
        }
        getchar();
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                scanf("%c",&c);
                if(c=='P')
                    g1[i].push_back(j);
                else if(c=='Q')
                    g2[i].push_back(j);
            }
            getchar();
        }
        bool flag1=true,flag2=true;
        for(int i=1;i<=n;i++) {
            if(!vis1[i])
                flag1=bfs(i,g1);
            if(!flag1) break;
            if(!vis2[i])
                flag2=bfs(i,g2);
            if(!flag2) break;
        }
        if(!flag1 || !flag2)
            cout<<"N"<<endl;
        else
            cout<<"T"<<endl;
    }
}
