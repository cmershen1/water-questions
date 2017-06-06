#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    while (cin>>n) {
        vector<int> a;
        int cur=1;

        while(n>=cur) {
            a.push_back(cur);
            n-=cur;
            cur++;
        }
        if(n>0) {
            int x=a.back()+n;
            a.pop_back();
            a.push_back(x);
        }
        cout<<a.size()<<endl;
        for(int i=0;i<a.size()-1;i++) {
            cout<<a[i]<<' ';
        }
        cout<<a.back()<<endl;
    }
}
