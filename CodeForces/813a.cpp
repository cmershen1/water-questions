#include <bits/stdc++.h>
using namespace std;

int n,m;
int a;
int l,r;

int main() {
    while (cin >> n) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            cin >> a;
            sum += a;
        }
        cin >> m;
        int ans = -1;
        int l2 = 0, r2 = 0;
        for (int i=0; i<m; i++) {
            l2 = l, r2 = r;
            cin >> l >> r;
            if (ans == -1) {
                if (l <= sum && sum <= r)
                    ans = sum;
                if (r2 <= sum && sum < l)
                    ans = l;
            }
        }
        cout << ans <<endl;
    }
}
