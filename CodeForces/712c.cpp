#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    vector<int> p;
    p.push_back(y);p.push_back(y);p.push_back(y);
    int cnt=0;
    while(p[0]!=x || p[1]!=x || p[2]!=x) {
        sort(p.begin(),p.end());
        p[0]=min(p[1]+p[2]-1,x);
        cnt++;
        cout<<p[0]<<' '<<p[1]<<' '<<p[2]<<endl;//debug
    }
    cout<<cnt<<endl;
}
