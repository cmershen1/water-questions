#include <bits/stdc++.h>
using namespace std;

#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define eps 1e-8

#define IN "D:/water-questions/temp/input/in.txt"
#define OUT "D:/water-questions/temp/input/out.txt"

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;

const int M = 1e9 + 7;
const double PI = acos(-1.0);

const int MAXN = 1e5;
const int MAXM = 1e6;

int main() {
    //RE(IN);WR(OUT);
    int n;
    int p[51];
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>p[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            if(p[p[j]]==i)
                cout<<j<<endl;
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> c3bc45e0265d2a23d3dc1f76e4b01a98c74f8382
