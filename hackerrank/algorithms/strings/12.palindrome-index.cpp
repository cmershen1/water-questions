#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPalindrome(string s) {
    int i=0,j=s.length()-1;
    while(i<j) {
        if(s[i++]!=s[j--])
            return false;
    }
    return true;
}
int main(){
    int t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        if(isPalindrome(s)) {
            cout<<-1<<endl;
        }
        else {
            int i=0,j=s.length()-1;
            while(i<j) {
                if(s[i]!=s[j])
                    break;
                else {
                    i++;
                    j--;
                }
            }
            string s1,s2;
            // if(i==0) {
            //     s1=s.substr(i+1);
            //     s2=s.substr(0,s.length()-1);
            // }
            // else {
                s1=s.substr(0,i)+s.substr(i+1);
                s2=s.substr(0,j)+s.substr(j+1);
            // }

            if(isPalindrome(s1))
                cout<<i<<endl;
            else if(isPalindrome(s2))
                cout<<j<<endl;
            else
                cout<<-1<<endl;

        }
    }

}
