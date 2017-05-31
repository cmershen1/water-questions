#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    int t;string d;
    while(cin>>n) {
        int dis=0;
        string ans="YES";
        while(n--) {
            cin>>t>>d;
            if(dis==0) {
                if(d!="South" || (d=="South" && t>20000)) {
                    ans="NO";
                } else {
                    dis+=t;
                    if(dis>20000) {
                        ans="NO";
                    }
                }
            } else if(dis==20000) {
                if(d!="North" || (d=="North" && t>20000)) {
                    ans="NO";
                } else {
                    dis-=t;
                    if(dis<0)
                        ans="NO";
                }
            } else {
                if(d=="South") {
                    dis+=t;
                    if(dis>20000) {
                        ans="NO";
                    }

                } else if(d=="North"){
                    dis-=t;
                    if(dis<0)
                        ans="NO";
                }
            }
        }
        if(ans=="YES" && dis!=0)
            ans="NO";
        cout<<ans<<endl;
    }
}
