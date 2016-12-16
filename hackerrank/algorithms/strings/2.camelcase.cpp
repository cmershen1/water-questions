#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin>>s;
    int ans=1;
    for(auto a:s) {
        if(a>='A' && a<='Z')
            ans++;
    }
    cout<<ans<<endl;
}
