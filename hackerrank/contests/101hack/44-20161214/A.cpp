#include <bits/stdc++.h>
using namespace std;

#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define eps 1e-8

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;

const int M = 1e9 + 7;
const double PI = acos(-1.0);

const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;

int main() {
    //RE("in.txt");WR("out.txt");
    int n;
    int a[105];
    cin>>n;
    for (int i = 0; i < n; i++) 
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++) {
        int temp=1;
        for(int j=i+1;j<n;j++) {
            if(a[j]-a[i]<=1)
                temp++;
        }
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
}