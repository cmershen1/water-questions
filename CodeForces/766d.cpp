#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200005
map<string, int> mp;
int f[MAXN],diff[MAXN];
int n,m,q;
void init() {
    for(int i=1;i<=n;i++) {
        f[i]=i;
        diff[i]=-1;
    }
}

int find(int x) {
    if(x==-1)
        return -1;
    return f[x]==x?x:f[x]=find(f[x]);
}

int Union(int x, int y) {
    x=find(x);
    y=find(y);
    if(x!=y) {
        f[x]=y;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>n>>m>>q) {
        init();
        string s;
        int cd=1;
        for(int i=0;i<n;i++) {
            cin>>s;
            if(mp.find(s)==mp.end())
                mp[s]=cd++;
        }
        int t;
        string x,y;
        while(m--) {
            cin>>t>>x>>y;
            int u=find(mp[x]),v=find(mp[y]);
            int u2=find(diff[u]), v2=find(diff[v]);
            if(t==1) {
                if(u2==v) {//是反义词
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                    Union(u,v);
                    if(u2!=-1 && v2!=-1) {
                        Union(u2,v2);
                    }
                    if(v2==-1 && u2!=-1) //v没有反义词而u有
                        diff[v]=u2;
                    if(u2==-1 && v2!=-1) //u没有反义词而v有
                        diff[u]=v2;
                }
            } else {
                if(u==v) {
                    cout<<"NO"<<endl;
                } else {
                    cout << "YES" << endl;
                    if(u2==-1)//u没有反义词
                        diff[u]=v;
                    else
                        Union(u2,v);
                    if(v2==-1)//u没有反义词
                        diff[v]=u;
                    else
                        Union(v2,u);
                }
            }
        }

        while(q--) {
            cin>>x>>y;
            int u=find(mp[x]),v=find(mp[y]);
            if(u==v)
                cout<<1<<endl;
            else if(find(diff[u])==find(v) || find(diff[v])==find(u))
                cout<<2<<endl;
            else
                cout<<3<<endl;
        }
    }
}
