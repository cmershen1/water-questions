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
string s;
set<int> a;
int n,x;
int main() {
    //RE(IN);WR(OUT);
    cin>>s;
    a.insert(s[0]-'a'+1);
    int cnt=1;
    for(int i=1;i<s.length();i++) {
        if(s[i]==s[i-1]) {
            cnt++;
        }
        else {
            cnt=1;
        }
        a.insert((s[i]-'a'+1)* cnt);
    }
    cin>>n;
    while(n--) {
        cin>>x;
        if(a.find(x)!=a.end())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}