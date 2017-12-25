#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int a[105];
    int cnt = 0;
    int flag = 0;
    string s;
    cin >> s;
    memset(a,0,sizeof(a));
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'V' && s[i+1] == 'K') {
            a[i] = 1, a[i+1] = 1;
            cnt++;
        }
    }

    for (int i = 0; i < s.length() - 1; i++) {
        if (((s[i] == 'V' && s[i+1] == 'V') || (s[i] == 'K' && s[i+1] == 'K')) && !a[i] && !a[i+1] ){
            flag = 1;
            break;
        }
    }

    cout << cnt + flag << endl;
}
