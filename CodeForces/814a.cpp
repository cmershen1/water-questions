#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[205], b[205];

int main() {
    while(cin >> n >> k) {
        int zero_pos = 0;
        for (int i=0; i<n; i++) {
            cin>>a[i];
            if (a[i] == 0) {
                zero_pos = i;
            }
        }
        for (int i=0; i<k; i++) {
            cin>>b[i];
        }
        if (k>=2) {
            cout << "Yes" << endl;
        } else {
            int flag = 1;//剩下部分是否单调递增 1是 0否
            if (zero_pos == 0) {
                for (int i=1; i<n; i++) {
                    if (a[i] <= a[i-1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag && b[0] < a[1])
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
            } else if (zero_pos == n-1) {
                for (int i=0; i<n-1; i++) {
                    if (a[i] <= a[i-1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag && b[0] > a[n-2])
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
            } else {
                for (int i=0; i<n; i++) {
                    if (i == zero_pos) {
                        if (a[i+1] <= a[i-1]) {
                            flag = 0;
                            break;
                        }
                    } else if (a[i] <= a[i-1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag && a[zero_pos-1] < b[0] && b[0] < a[zero_pos+1]) { // b[0] in (a[zero_pos-1], a[zero_pos+1])
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
            }
        }
    }
    return 0;
}
