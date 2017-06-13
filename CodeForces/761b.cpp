#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    int a[120];
    while(cin>>n>>m) {
        memset(a, 0, sizeof(a));
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        vector<int> vec;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            vec.push_back(x);
        }

        bool flag=false;
        for(int i=1;i<=m;i++) {
            vector<int> temp;
            for(int j=0;j<n;j++) {
                int diff = (i+a[j]+m)%m;
                temp.push_back(diff);
            }
            sort(temp.begin(),temp.end());
            bool same=true;
             for(int j=0;j<n;j++) {
                 if(temp[j]!=vec[j]) {
                     same=false;
                     break;
                 }
             }
             if(same) {
                 flag=true;
                 break;
             }
        }
        if(flag) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}
