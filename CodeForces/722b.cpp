#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int p[105];
string t;
bool flag=true;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    getchar();
    for(int i=0;i<n;i++) {
        getline(cin,t);
        if(!flag)
            break;
        else {
            int cnt=0;
            for(int j=0;t[j];j++) {
                if(t[j]=='a' || t[j]=='e'||t[j]=='i'||t[j]=='o'||t[j]=='u'||t[j]=='y')
                    cnt++;
            }
            //cout<<cnt<<endl;
            if(cnt!=p[i])
                flag=false;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
