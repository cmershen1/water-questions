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
    string s;
    while(cin>>s)
    {
    //cin>>s;

        string t=s;
        for(int i=1;i<t.length();i++)
            t[i]=t[0];
        int i=1,j=t.length()-1;
        int cnt=1;
        while(i<=j) {
            while(i<=j && s[i]==s[i-1])
                i++;
            while(i<=j && s[j]==s[i-1])
                j--;
            if(i<=j) {
                for(int k=i;k<=j;k++) {
                    t[k]=s[i-1];
                }
                //cout<<t<<endl;
                cnt++;
                i++;
            }
        }
        cout<<cnt<<endl;
    }
}
