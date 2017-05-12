#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct chess{
    char type;
    int x,y;
};
chess ch[10];
bool vis[10];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int x0,y0,x,y;
    char c;
    cin>>x0>>y0;
    memset(vis,0,sizeof(vis));
    while(n--) {
        cin>>c>>x>>y;
        if(x==x0) {
            if(y>y0) { //上方
                if(!vis[1] || (vis[1] && ch[1].y>y)) {
                    vis[1] = true;
                    ch[1] = {c, x, y};
                }
            } else if(y<y0) {//下方
                if(!vis[5] || (vis[5] && ch[5].y<y)) {
                    vis[5] = true;
                    ch[5] = {c, x, y};
                }
            }
        } else if (y==y0) {
            if(x>x0) { //右方
                if(!vis[3] || (vis[3] && ch[3].x>x)) {
                    vis[3] = true;
                    ch[3] = {c, x, y};
                }
            } else if(x<x0) {//下方
                if(!vis[7] || (vis[7] && ch[7].x<x)) {
                    vis[7] = true;
                    ch[7] = {c, x, y};
                }
            }
        } else if(x-x0 == y-y0) { //斜率1
            if(y>y0) { //右上
                if(!vis[2] || (vis[2] && ch[2].x>x)) {
                    vis[2] = true;
                    ch[2] = {c, x, y};
                }
            } else if(y<y0) { //左下
                if(!vis[6] || (vis[6] && ch[6].x<x)) {
                    vis[6] = true;
                    ch[6] = {c, x, y};
                }
            }
        } else if(x-x0 == y0-y) {
            if(y>y0) {//左上
                if(!vis[8] || (vis[8] && ch[8].y>y)) {
                    vis[8] = true;
                    ch[8] = {c, x, y};
                }
            } else if(y<y0) {//右下
                if(!vis[4] || (vis[4] && ch[4].y<y)) {
                    vis[4] = true;
                    ch[4] = {c, x, y};
                }
            }
        }
    }
    bool flag = false;
    for(int i=1;i<=8;i++) {
        if(!vis[i]) continue;
        if((i&1) && ch[i].type!='B')
            flag = true;
        if(!(i&1) && ch[i].type!='R')
            flag = true;
    }
    if(flag) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
