#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(s) freopen(s,"r",stdin)
#define WR(s) freopen(s,"w",stdout)
int main(){
    RE("in.txt");
    WR("out.txt");
    int n,k;
    string s;
    cin>>n>>k>>s;
    int vis[100005];
    memset(vis,0,sizeof(vis));
    int i=0,j=n-1;
    while(i<j) {
        if(s[i]>s[j]) {
            s[j]=s[i];
            vis[j]=1;
            k--;
        }
        else if(s[i]<s[j]) {
            s[i]=s[j];
            vis[i]=1;
            k--;
        }
        i++;j--;
    }
    if(k<0)
        cout<<-1<<endl;
    else {
        i=0;j=n-1;
        while(i<j && k>0) {
            if(vis[i]^vis[j]) {//有一个为1，说明改了一边
                vis[i]=vis[j]=true;
                s[i]=s[j]='9';
                k--;
                i++;j--;
            }
            else { //两边都没改
                if(k>=2 && s[i]!='9') {
                    s[i]=s[j]='9';
                    k-=2;
                }
                i++;j--;
            }
        }
        if(i==j && k)
            s[i]=s[j]='9';
        cout<<s<<endl;
    }

}
