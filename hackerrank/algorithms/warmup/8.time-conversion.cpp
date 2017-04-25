#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    char t[12];
    scanf("%s",t);
    if(t[8]=='A') {
        int h = (t[0]-'0')*10+t[1]-'0';
        if(h==12) {
            t[0]=t[1]='0';
        }
        for(int i=0;i<8;i++) {
            printf("%c", t[i]);
        }
        printf("\n");
        return 0;
    }
    else {
        int h = ((t[0]-'0')*10+t[1]-'0')%12+12;
        t[0]=h/10+'0';
        t[1]=h%10+'0';
        for(int i=0;i<8;i++) {
            printf("%c", t[i]);
        }
        printf("\n");
        return 0;

    }

}
