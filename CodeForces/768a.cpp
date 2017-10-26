#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;

    while(cin>>n) {
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int a;
            cin>>a;
            m[a]++;
        }
        auto it1 = m.begin(), it2 = --m.end();

        int ans = n - it1->second - it2->second;
        (ans >= 0) || (ans = 0);
        cout<<ans<<endl;
    }

}
