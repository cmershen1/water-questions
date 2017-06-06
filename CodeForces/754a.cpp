#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    int a[110];

    while(cin>>n) {
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        int i=1,j=1,cur_sum=a[1];
        vector<pair<int, int> > ans;
        while(j<=n) {
            if(cur_sum!=0) {
                ans.push_back(make_pair(i,j));
                j++;
                i=j;
                cur_sum=a[i];
            } else {
                j++;
                cur_sum+=a[j];
            }
        }
        if(ans.size() > 0 && i<j && a[n]==0) {
            i=j;
            ans.back().second=n;
        }
        if(i==j) {
            cout<<"YES"<<endl;
            cout<<ans.size()<<endl;
            for(auto i : ans) {
                cout<<i.first<<' '<<i.second<<endl;
            }
        } else {
            cout<<"NO"<<endl;
        }
    }
}
