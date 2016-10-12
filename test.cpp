#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> tree1[100];
int val1[100];
vector<int> tree2[100];
int val2[100];
int ans=0;
void dfs(int a,int b,int dep) {
    printf("Current Node: Tree1=%d Tree2=%d Depth=%d\n", a,b,dep);
    if(dep>ans)
        ans=dep;
    if(val1[a] == val2[b]) {
        for(int i=0;i<tree1[a].size();i++) {
            int m=tree1[a][i];
            for(int j=0;j<tree2[b].size();j++) {
                int n=tree2[b][j];
                printf("val1[%d]=%d,val2[%d]=%d\n", m,val1[m],n,val2[n]);
                if(val1[m] == val2[n])
                    dfs(m,n,dep+1);
            }
        }

    }
}
int main() {
    int x1,x2;//t1有x1个点，t2有x2个点
    int u,v;
    cin>>x1;
    for(int i=0;i<x1-1;i++) {
        cin>>u>>v;
        tree1[u].push_back(v);
    }
    for(int i=1;i<=x1;i++) {
        cin>>val1[i];
    }
    cin>>x2;
    for(int i=0;i<x2-1;i++) {
        cin>>u>>v;
        tree2[u].push_back(v);
    }
    for(int i=1;i<=x2;i++) {
        cin>>val2[i];
    }
    dfs(1,1,0);
    cout<<ans+1<<endl;
}
/*
7   
1 2
1 3
1 4
1 5
3 6
3 7
1 2 3 4 5 6 7
9
1 2
1 3
1 4
1 9
2 5
2 6
3 7
3 8
1 8 3 5 10 11 12 7 13
*/
