#include <bits/stdc++.h>
using namespace std;

int main () {
    int a,b;
    while (cin>>a>>b) {
        int i = 1, flag = 0;
        while (1) {
            if (flag == 0 && a < i) break;
            if (flag == 1 && b < i) break;
            if (flag == 0) a-=i;
            else b-=i;
            i++;
            flag = 1-flag;
            //cout<<a<<' '<<b<<endl;
        }
        if (flag == 1)
            cout<<"Valera"<<endl;
        else
            cout<<"Vladik"<<endl;
    }
}
