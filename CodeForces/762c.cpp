#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
string s1,s2;
int l1,l2;
int pre[MAXN],suf[MAXN];

void init() {
    l1 = s1.length(),l2 = s2.length();
    s1 = " " + s1, s2 = " " + s2; //1-base
    for(int i=1;i<=l2;i++) {
        pre[i]=l1+1;
        suf[i]=0;
    }

    int i = 1,j = 1;
    while (i <= l1) {
        if (s1[i] == s2[j]) pre[j++]=i;
        i++;
    }
    i = l1, j = l2;
    while (i > 0) {
        if (s1[i] == s2[j]) suf[j--]=i;
        i--;
    }
    pre[0] = 0;
    suf[l2 + 1] = l1 + 1;
}

int exist(int len) {
    for(int i=1;i+len<=l2+1;i++) {
        if(pre[i-1] < suf[i+len])
            return i;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>s2;
    init();
    int l = 0, r = l2 - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (exist(mid) != -1)
            r = mid;
        else l = mid + 1;
    }
    int t = exist(l);
    if(l == r && t != -1) {
        string s3 = s2.substr(1, t - 1) + s2.substr(t + l, s2.length() - t - l);
        cout << s3 << endl;
    } else {
        cout << '-' << endl;
    }
}
