#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int T;
int a[7][5];
bool same(int x[]) {
    return x[1]==x[2] && x[2]==x[3] && x[3]==x[4];
}
bool same(int x[][5]) {
    return same(x[1]) && same(x[2]) && same(x[3]) && same(x[4]) && same(x[5]) && same(x[6]);
}

bool can() {
    //如果六个面就是同色的 那就ok
    set<int> s;
    for(int i=1;i<=6;i++)
        for(int j=1;j<=4;j++)
            s.insert(a[i][j]);
    if(s.size()!=6)
        return false;
    else if(same(a))
        return true;
    else {
        int b[7][5];
        memcpy(b,a,sizeof(b));
        //拧法1 右面顺时针转
        b[1][2]=a[2][2];b[1][4]=a[2][4];
        b[4][2]=a[1][2];b[4][4]=a[1][4];
        b[3][2]=a[4][2];b[3][4]=a[4][4];
        b[2][2]=a[3][2];b[2][4]=a[3][4];
        b[6][1]=a[6][3];b[6][2]=a[6][1];b[6][3]=a[6][4];b[6][4]=a[6][2];
        if(same(b))
            return true;

        //拧法2 右面逆时针转
        memcpy(b,a,sizeof(b));
        b[1][2]=a[4][2];b[1][4]=a[4][4];
        b[4][2]=a[3][2];b[4][4]=a[3][4];
        b[3][2]=a[2][2];b[3][4]=a[2][4];
        b[2][2]=a[1][2];b[2][4]=a[1][4];
        b[6][1]=a[6][2];b[6][2]=a[6][4];b[6][3]=a[6][1];b[6][4]=a[6][3];
        if(same(b))
            return true;

        //拧法3 上面逆时针转
        memcpy(b,a,sizeof(b));
        b[2][1]=a[6][3];b[2][2]=a[6][1];
        b[6][3]=a[4][4];b[6][1]=a[4][3];
        b[4][4]=a[5][2];b[4][3]=a[5][4];
        b[5][2]=a[2][1];b[5][4]=a[2][2];


        b[1][1]=a[1][2];b[1][2]=a[1][4];b[1][3]=a[1][1];b[1][4]=a[1][3];
        if(same(b))
            return true;

        //拧法4 上面顺时针转
        memcpy(b,a,sizeof(b));
        b[2][1]=a[5][2];b[2][2]=a[5][4];
        b[6][3]=a[2][1];b[6][1]=a[2][2];
        b[4][4]=a[6][3];b[4][3]=a[6][1];
        b[5][2]=a[4][4];b[5][4]=a[4][3];

        b[1][1]=a[1][3];b[1][2]=a[1][1];b[1][3]=a[1][4];b[1][4]=a[1][2];
        if(same(b))
            return true;
        //拧法5 前面顺时针转cwjs,dxit
        memcpy(b,a,sizeof(b));
        b[1][3]=a[5][3];b[1][4]=a[5][4];
        b[5][3]=a[3][2];b[5][4]=a[3][1];
        b[3][2]=a[6][3];b[3][1]=a[6][4];
        b[6][3]=a[1][3];b[6][4]=a[1][4];
        b[2][1]=a[2][3];b[2][2]=a[2][1];b[2][3]=a[2][4];b[2][4]=a[2][2];
        if(same(b))
            return true;

        //拧法6 前面逆时针转
        memcpy(b,a,sizeof(b));
        b[1][3]=a[6][3];b[1][4]=a[6][4];
        b[5][3]=a[1][3];b[5][4]=a[1][4];
        b[3][2]=a[5][3];b[3][1]=a[5][4];
        b[6][3]=a[3][2];b[6][4]=a[3][1];
        b[2][1]=a[2][2];b[2][2]=a[2][4];b[2][3]=a[2][1];b[2][4]=a[2][3];
        if(same(b))
            return true;
        return false;
    }
}
int main() {
    RE("in.txt");
    WR("out.txt");
    scanf("%d",&T);
    while(T--) {
        for(int i=1;i<=6;i++)
            for(int j=1;j<=4;j++)
                scanf("%d",&a[i][j]);
        if(can()) {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}
