#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,w,k;
    int ans;
    cin >> n >> k;
    while (n--) {
        cin >> w;
        ans += ceil(w * 1.0 / k);
    }
    ans = ceil(ans * 1.0 / 2);
    cout << ans << endl;
}
