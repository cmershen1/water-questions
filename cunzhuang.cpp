#include <bits/stdc++.h>
using namespace std;

#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define INF 0x3f3f3f3f
#define CLEAR(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int M = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-8;
int n,m;
int f[111];
int find(int x) {
    if(f[x]!=x)
		f[x]=find(f[x]);
	return f[x];
}
void un(int a,int b)/*合并a和b*/
{
	int p=find(a);
	int q=find(b);
	if(p!=q)
	{
		f[p]=q;
	}
}
int main() {
    //RE("in.txt");WR("out.txt");
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        f[i]=i;
    }
    while(m--) {
        int a,b;
        cin>>a>>b;
        un(a,b);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        if(f[i]==i)
            sum++;
    cout<<sum-1<<endl;
}
