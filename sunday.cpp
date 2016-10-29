/*
*@author:cmershen
*@description:Sunday算法模板，求字符串匹配个数
*/

#include <bits/stdc++.h>
using namespace std;

int SUNDAY(int *text, int *patt,int n,int m)
{
    int cnt = 0;
    register size_t temp[256];
    size_t *shift = temp;
    size_t i, patt_size = m, text_size = n;
    //cout << "size : " << patt_size << endl;
    for( i=0; i < 256; i++ )
    {
        *(shift+i) = patt_size+1;
    }
    for( i=0; i < patt_size; i++ )
    {
        *(shift+(unsigned char)(*(patt+i))) = patt_size-i;
    }
    //shift['s']=6 步,shitf['e']=5 以此类推
    size_t limit = text_size - patt_size+1;
    for(i=0; i < limit; i += shift[ text[i+patt_size] ])
    {
        if( text[i] == *patt )
        {
            int *match_text = text + i + 1;
            size_t match_size = 1;
            do
            {
                // 输出所有匹配的位置
                if( match_size == patt_size )
                {
                    //cout << "the NO. is " << i << endl;
                    cnt++;
                }
            }while((*match_text++) == patt[match_size++]);
        }
    }
    //cout << endl;
    return cnt;
}
int main(void)
{
    int text[17] = {1,2,3,4,5,6,7,8,9,5,6,7,2,3,4,5,6};
    int patt[3] = {3,6};

    int text2[1000];
    for(int i=0;i<3;i++) {
        int d=0,s=i;
        while(s<17) {
            text2[d]=text[s];
            d++;
            s+=3;
        }
        cout<<SUNDAY(text2,patt,d,2)<<endl;
    }


    //cout << SUNDAY(text, patt,17,3) << endl;
    return 0;
}
