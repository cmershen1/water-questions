#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005];
int p[100005];
int f[100005]; // 记录每个节点的父亲
//int Rank[100005];// 记录每个节点所在集合的高度,做路径压缩
ll sum[100005];// 记录每个节点所在集合的和
ll ans[100005];//记录最终答案
bool vis[100005];//记录每个点是不是在集合里面
ll m=0;//动态更新每个树根的最大值
int find(int x) {
    //return x==f[x]?x:f[x]=find(f[x]);
    return x==f[x]?x:find(f[x]);
}
void Union(int i,int j) {
    i=find(i);
    j=find(j);
    sum[i]=sum[j]=sum[i]+sum[j];
    // if(Rank[i]>Rank[j]) {
    //     f[j]=i;
    //     Rank[j]++;
    // }
    // else {
    //     f[i]=j;
    //     Rank[i]++;
    // }
    f[i]=j;
}
int main() {
    memset(vis,0,sizeof(vis));
    memset(Rank,0,sizeof(Rank));
    memset(sum,0,sizeof(sum));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    ans[n]=0;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=n;i>1;i--) {
        int id=p[i];//当前要加入集合的id
        sum[id]=a[id];
        if(vis[id-1])
            Union(id-1,id);
        if(vis[id+1])
            Union(id+1,id);
        if(sum[id]>m)
            m=sum[id];
        vis[id]=1;
        ans[i-1]=m;
    }
    for(int i=1;i<=n;i++) {
        printf("%I64d\n", ans[i]);
    }
}
