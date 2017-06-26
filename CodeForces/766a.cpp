#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    if(a==b)
        cout<<-1<<endl;
    else
        cout<<max(a.length(), b.length())<<endl;

}
