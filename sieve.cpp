/**
* 埃拉托色尼筛选法找素数，时间复杂度据说是O(nlog log n),经测试1秒钟能跑3e8的数据
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200;
bool isPrime[MAXN + 10];
int prime[MAXN];
int main() {
    for(int i=1;i<=MAXN;i++) {
        isPrime[i]=true;
    }
    int cnt=0;
    clock_t start = clock();
    for(int i=2;i<=MAXN;i++) {
        if(isPrime[i]) {
            prime[cnt++]=i;
            for(int j=i*2;j<=MAXN;j+=i) {
                isPrime[j]=false;
            }
        }
    }
    clock_t end = clock();
    cout << (double)(end - start) << endl;
    for(int i=cnt-100;i<cnt;i++) {
        cout<<prime[i]<<endl;
    }
}
