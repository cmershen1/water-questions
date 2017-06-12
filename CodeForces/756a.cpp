#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[200005],b[200005];
int n;

int vis[200005];
void dfs(int u) {
    if(vis[u]) 
        return;
    vis[u]=1;
    dfs(p[u]);
}
int main() {
    while(cin >> n) {
	    for(int i=1;i<=n;i++) {
	        cin>>p[i];
	    }
	    for(int i=1;i<=n;i++) {
	        cin>>b[i];
	    }
	    memset(vis, 0, sizeof(vis));
	    int round=0;
	    for(int i=1;i<=n;i++) {
	        if(!vis[i]) {
	            round++;
	            dfs(i);
	        }
	    }
	    int a=(round>1)?round:0;
	    int temp=0;
	    for(int i=1;i<=n;i++) {
	        temp+=b[i];
	    }
	    if(temp&1)  
	        cout<<a<<endl;
	    else
	        cout<<a+1<<endl;
    }
}

