#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
ll M = 2147493647L;
class Matrix{
public:
    ll mat[7][7]={
        {1,2,1,4,6,4,1},
        {1,0,0,0,0,0,0},
        {0,0,1,4,6,4,1},
        {0,0,0,1,3,3,1},
        {0,0,0,0,1,2,1},
        {0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1}
    };
    Matrix operator*(const Matrix& m)const{
        Matrix tmp;
        for(int i = 0 ; i < 7; i++){
            for(int j = 0 ; j < 7 ; j++){
                tmp.mat[i][j] = 0;
                for(int k = 0 ; k < 7 ; k++){
                    tmp.mat[i][j] += mat[i][k]*m.mat[k][j]%M;
                    tmp.mat[i][j] %= M;
                }
            }
        }
        return tmp;
    }

};
Matrix Pow(Matrix &m , int k){
    Matrix ans;
    memset(ans.mat , 0 , sizeof(ans.mat));
    for(int i = 0 ; i < 7 ; i++)
        ans.mat[i][i] = 1;
    while(k){
        if(k&1)
            ans = ans*m;
        k >>= 1;
        m = m*m;
    }
    return ans;
}
int T;
int main() {
    RE("in.txt");
    WR("out.txt");
    int T;
    ll a,b,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%I64d %I64d %I64d",&n,&a,&b);
        Matrix m;
        Matrix A=Pow(m,n-2);
        ll ans=(A.mat[0][0]*b+A.mat[0][1]*a+A.mat[0][2]*16+A.mat[0][3]*8+A.mat[0][4]*4+A.mat[0][5]*2+A.mat[0][6]*1)%M;
        cout<<ans<<endl;
    }
}
