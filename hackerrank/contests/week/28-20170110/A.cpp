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

const int MAXN = 1e5;
const int MAXM = 1e6;

int main() {
    //RE("in.txt");WR("out.txt");
    int n,c,m,p;
    cin>>n>>c>>m;
    string s="Yes";
    while(n--) {
        cin>>p;
        if(c*m<p)
            s="No";
    }
    cout<<s<<endl;
}