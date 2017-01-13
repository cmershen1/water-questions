#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int g,p;
    cin>>g;
    while(g--) {
        int sg=0,t;
        cin>>t;
        while(t--) {
            cin>>p;
            if(p&1)
                sg^=p+1;
            else
                sg^=p-1;
        }
        if(sg)
            cout<<"W"<<endl;
        else
            cout<<"L"<<endl;
    }
    return 0;
}
