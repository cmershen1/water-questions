#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,m;
    cin >> n >> m;
    set<string> a,b;
    while(n--) {
        string s;
        cin >> s;
        a.insert(s);
    }
    while(m--) {
        string s;
        cin >> s;
        b.insert(s);
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(string s : a) {
        if(b.find(s) == b.end())
            cnt1++;
        else 
            cnt3++;
    }
    for(string s : b) {
        if(a.find(s) == a.end()) 
            cnt2++;
    }
    if(cnt3 & 1) {
        if(cnt1>=cnt2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
	    if(cnt1>cnt2)
	        cout << "YES" << endl;
	    else
	        cout << "NO" << endl;
    }
}
