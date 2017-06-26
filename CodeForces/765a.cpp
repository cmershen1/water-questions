#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
string home;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        cin>>home;
        int cnt=0;
        for(int i=1;i<=n;i++) {
            cin>>s;
            string s1=s.substr(0,3), s2=s.substr(5,3);
            if(s1==home)
                cnt++;
            if(s2==home)
                cnt++;
        }
        if(cnt&1 == 0)
            cout<<"home"<<endl;
        else
            cout << "contest" << endl;
    }
}
