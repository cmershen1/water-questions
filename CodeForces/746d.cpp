#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,k,a,b;
    test:while(cin>>n>>k>>a>>b) {
        if(a==b) {
            for(int i=0;i<n/2;i++) {
                cout<<"GB";
            }
            cout<<endl;
        } else if(a>b) {
            int rest_g=a,rest_b=b;
            int diff=a-b;
            string ans="";
            while(diff>k) {
                if(rest_b==0) {
                    cout<<"NO"<<endl;
                    goto test;
                }
                for(int i=0;i<k;i++) {
                    ans+='G';
                }
                ans+='B';
                diff-=(k-1);
                rest_g-=k,rest_b-=1;
            }
            for(int i=0;i<diff;i++) {
                ans+='G';
            }
            for(int i=0;i<rest_b;i++) {
                ans+="BG";
            }
            cout<<ans<<endl;
        } else {
            int rest_g=a,rest_b=b;
            int diff=b-a;
            string ans="";
            while(diff>k) {
                if(rest_g==0) {
                    cout<<"NO"<<endl;
                    goto test;
                }
                for(int i=0;i<k;i++) {
                    ans+='B';
                }
                ans+='G';
                diff-=(k-1);
                rest_b-=k,rest_g-=1;
            }
            for(int i=0;i<diff;i++) {
                ans+='B';
            }
            for(int i=0;i<rest_g;i++) {
                ans+="GB";
            }
            cout<<ans<<endl;
        }
    }
}
