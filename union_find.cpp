#include <bits/stdc++.h>
#define N 1005
#define eps 1e-9
#define pi acos(-1.0)
#define P system("pause")
using namespace std;
int f[N];
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int n,m;
    while(scanf("%d",&n) && n)
    {
         scanf("%d",&m);
         int i;
         int x,y;
         for(i = 0; i <= n; i++)
               f[i] = i;
         for(i = 0; i < m; i++)
         {
               scanf("%d%d",&x,&y);
               x = find(x);
               y = find(y);
               if(x != y) f[x] = y;
         }
         int ans = 0;
         for(i = 1; i <= n; i++)
        // {cout<<f[i]<<" ";
                 if(f[i] == i)
                      ans++;
         //}cout<<endl;
         printf("%d\n",ans);
    }

  //  P;
    return 0;
}
