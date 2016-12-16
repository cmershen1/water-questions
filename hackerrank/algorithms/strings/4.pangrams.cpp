#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    int m[26];
    memset(m,0,sizeof(m));
    getline(cin,s);
    for(int i=0;i<s.length();i++) {
        char a=s[i];
        if(a!=' ') {
            if(a>='A' && a<='Z')
                a+=32;
            m[a-'a']++;
        }
    }
    sort(m,m+26);
    puts(m[0]?"pangram":"not pangram");

}
