/*
*@author:cmershen
*@description:并查集模板，判断两个人是否在同一个朋友圈里面
*/
#include<iostream>
using namespace std;
const int maxn =2e5+10;
int p[maxn];
int Find(int x){
    return p[x]==x?x:p[x]=Find(p[x]);
}
void Union(int x,int y){
    p[Find(x)]=Find(y);
}
bool same(int x,int y)
{
    return Find(x)==Find(y);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=2e5;i++)p[i]=i;
    int op,now=0;

    int a,b;
    while(n--){
        cin>>op>>a>>b;
        if(op==0){
            Union(q[a],q[b]);
        }
        else{
            if(same(q[a],q[b]))cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }
    return 0;
}
