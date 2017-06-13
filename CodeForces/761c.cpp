#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char ch[100][100];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>n>>m) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>ch[i][j];
            }
        }

        int ans=INT_MAX;
        for(int i=1;i<=n;i++) {//digit
            int digit=m+1;
            for(int s=1;s<=m;s++) {
                if(ch[i][s] >= '0' && ch[i][s] <= '9') {
                    digit=min(digit, min(s-1, m+1-s));
                }
            }
            if(digit>ans)
                continue;
            for(int j=1;j<=n;j++) {//letter
                if(j==i)
                    continue;
                int letter=m+1;
                for(int s=1;s<=m;s++) {
                    if(ch[j][s] >= 'a' && ch[j][s] <= 'z') {
                        letter=min(letter, min(s-1, m+1-s));
                    }
                }
                if(digit+letter>ans)
                    continue;
                for(int k=1;k<=n;k++) {//symbol
                    if(k==i || k==j)
                        continue;
                    int symb = m+1;
                    for(int s=1;s<=m;s++) {
                        if(ch[k][s] == '#' || ch[k][s] == '&' || ch[k][s] == '*') {
                            symb = min(symb, min(s-1, m+1-s));
                            ans=min(ans, digit+letter+symb);
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
