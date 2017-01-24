#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> vp;//key=movie ID,value=very pleased scientists
map<int,int> as;//key=movie ID,value=almost satisfied scientists
map<int,int> l;//key=language ID,value=count of scientists who knows the language
int b,c;
int main() {
    int n,a,m;
    int maxvp=-1,maxas=-1,ansi=-1;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&a);
        l[a]++;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        scanf("%d",&b);
        vp[i]+=l[b];
    }
    for(int i=0;i<m;i++) {
        scanf("%d",&c);
        as[i]+=l[c];
    }
    for(map<int,int>::iterator i=vp.begin();i!=vp.end();i++) {
        int id=i->first;
        if(i->second > maxvp) {
            maxvp=i->second;
            maxas=as[id];
            ansi=id;
        }
        else if(i->second == maxvp && as[id]>maxas) {
            maxas=as[id];
            ansi=id;
        }
    }
    printf("%d\n", ansi+1);
}
