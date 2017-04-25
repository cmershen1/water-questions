#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
int s[100005];
set<int> f;//n的约数
map<int,int> m1,m2;
vector<int> ans;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&s[i]);
        }

        for(int i=1;i<=n;i++) {
            if(n%i==0) { //i是候选解
                bool flag=true;
                m1.clear();
                for(int j=0;j<i;j++) //第0段，从s[0]~s[i-1]
                    m1[s[j]]++;

                int x=n/i;//x段
                for(int j=1;j<x;j++) { //第1~x-1段
                    m2=m1;
                    for(int k=j*i;k<(j+1)*i;k++) {
                        m2[s[k]]--;
                        if(m2[s[k]]<0) {
                            flag=false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if(flag) {
                    if(i!=n)
                        printf("%d ", i);
                    else
                        printf("%d", n);
                }
            }

        }
        printf("\n");
    }

}
