#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int c[200005], d[200005];
int main() {

    while(cin>>n) {
        for(int i=0;i<n;i++) {
            cin>>c[i]>>d[i];
        }
        int min_rating=-200000*2000,max_rating=200000*2000;
        for(int i=0;i<n;i++) {
            if(max_rating<min_rating) {
                break;
            }
            if(d[i]==1) {
                min_rating=max(min_rating,1900);
            } else {
                max_rating=min(max_rating,1899);
            }
            min_rating+=c[i];
            max_rating+=c[i];
            //cout<<min_rating<<','<<max_rating<<endl;
        }
        if(max_rating<min_rating)
            cout<<"Impossible"<<endl;
        else if(max_rating>200000*1000)
            cout<<"Infinity"<<endl;
        else
            cout<<max_rating<<endl;
    }
}
