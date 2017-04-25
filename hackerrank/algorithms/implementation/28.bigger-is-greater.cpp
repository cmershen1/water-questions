#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    char s[111];
    char s2[111];
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s);
        int l=strlen(s);

        if(!next_permutation(s,s+l))
            cout<<"no answer"<<endl;
        else
            cout<<s<<endl;
    }
}
