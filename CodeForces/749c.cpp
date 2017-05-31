#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;string s;
    while(cin>>n>>s) {
        queue<int> r,d;
        for(int i=0;i<n;i++) {
            if(s[i]=='D')
                d.push(i);
            else
                r.push(i);
        }
        while(!d.empty() && !r.empty()) {
            int cur_id,cur_ch;
            if(d.front() < r.front()) {
                cur_id = d.front();
                d.pop();
                cur_ch = 1;
            } else {
                cur_id = r.front();
                r.pop();
                cur_ch = 2;
            }
            if(cur_ch==1) {
                r.pop();
                d.push(cur_id+n);
            } else {
                d.pop();
                r.push(cur_id+n);
            }
        }
        if(d.empty())
            cout<<"R"<<endl;
        else
            cout<<"D"<<endl;
    }
}
