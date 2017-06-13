#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c;
    vector<int> u,p;
    while(cin>>a>>b>>c) {
        int n,val;
        cin>>n;
        string s;
        u.clear();p.clear();
        while(n--) {
            cin>>val>>s;
            if(s=="USB")
                u.push_back(val);
            else
                p.push_back(val);
        }
        int computers=0;
        ll total_cost=0;
        int p1=0,p2=0;
        sort(u.begin(), u.end());
        sort(p.begin(), p.end());

        while(a) { //usb
            if(p1<u.size()) {
                computers++;
                total_cost+=u[p1++];
                a--;
            } else {
                break;
            }
        }

        while(b) { //ps2
            if(p2<p.size()) {
                computers++;
                total_cost+=p[p2++];
                b--;
            } else {
                break;
            }
        }

        while(c) {
            if(p1==u.size()) {
                if(p2==p.size())
                    break;
                else {
                    computers++;
                    total_cost+=p[p2++];
                    c--;
                }
            } else {
                if(p2==p.size()) {
                    computers++;
                    total_cost+=u[p1++];
                    c--;
                } else {
                    if(u[p1]<p[p2]) {
                        computers++;
                        total_cost+=u[p1++];
                        c--;
                    } else {
                        computers++;
                        total_cost+=p[p2++];
                        c--;
                    }
                }
            }
        }
        cout<<computers<<' '<<total_cost<<endl;
    }
}
