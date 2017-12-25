#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[4][4];
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cin >> a[i][j];
        }
    }
    string ans = "NO";
    for(int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            if (a[i][j] &&  (a[(i+3-j)%4][3] || a[i][3]))
                ans = "YES";
        }
    }
    cout << ans << endl;
}
