#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int T,n;
    scanf("%d",&T);
    vector<int> v;
    while(T--) {
        scanf("%d",&n);
        v.clear();
        for(int i=n;i>0;i--) {
            v.insert(v.begin(),i);
            int t=v[v.size()-1];
            v.pop_back();
            v.insert(v.begin(),t);
        }
        for(int i=0;i<v.size()-1;i++)
            printf("%d ", v[i]);
        printf("%d\n", v[v.size()-1]);
    }
}
