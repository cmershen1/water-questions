#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[105];
vector<int> v;
int main() {
    scanf("%d\n",&n);
    scanf("%s",s);

    int i=0,cnt=0;
    while(i<n) {
        if(s[i]=='W' && cnt>0) {
            v.push_back(cnt);
            cnt=0;
        }
        else if(s[i]=='B') {
            cnt++;
            if(i==n-1)
                v.push_back(cnt);
        }
        i++;
    }
    if(v.size()==0) {
        printf("0");
        return 0;
    }
    printf("%d\n", v.size());
    for(int i=0;i<v.size()-1;i++)
        printf("%d ", v[i]);
    printf("%d\n", v.back());
}
