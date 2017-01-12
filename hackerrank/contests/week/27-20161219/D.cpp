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

int main() {
    //RE("in.txt");WR("out.txt");
    int g,p;
    cin>>g;
    while(g--) {
        int sg=0,t;
        cin>>t;
        while(t--) {
            cin>>p;
            if(p&1)
                sg^=p+1;
            else
                sg^=p-1;
        }
        if(sg)
            cout<<"W"<<endl;
        else
            cout<<"L"<<endl;
    }
    return 0;
}
