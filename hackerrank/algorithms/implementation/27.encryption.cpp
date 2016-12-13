#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int main(){
    RE("in.txt");
    WR("out.txt");
    char s[100];
    cin>>s;
    int row=floor(sqrt(strlen(s)*1.0));
    int col=ceil(sqrt(strlen(s)*1.0));
    if(row*col<strlen(s))
        row++;
    char a[row][col];
    memset(a,0,sizeof(a));
    int i=0,j=0,p=0;
    while(p<strlen(s)) {
        a[i][j]=s[p++];
        if(j==col-1) {
            i++;
            j=0;
        }
        else
            j++;
    }
    for(int i=0;i<col;i++) {
        for(int j=0;j<row;j++) {
            if(!a[j][i])
                break;
            cout<<a[j][i];
        }
        if(i!=col-1)
            cout<<" ";
    }
    //cout<<endl;
}
