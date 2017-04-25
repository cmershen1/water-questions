#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
string s;
map<vector<int>,int> m;
int main(){
    cin>>t;
    while(t--) {
        cin>>s;
        vector<int> v(26);
        int n=s.length();
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                v[s[j]-'a']++;
                m[v]++;
            }
            for(int j=0;j<26;j++)
                v[j]=0;
        }
        ll ans=0;
        for (auto &kv : m) {
            int val=kv.second;
            ans+=val*(val-1)/2;
        }
        m.clear();
        cout<<ans<<endl;
    }
}
