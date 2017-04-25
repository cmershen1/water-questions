/**
*@author:cmershen
*@description:二分染色，邻接表表示。paint()返回true表示可以二分染色
*/

int p[510];//记录每个点的颜色,0没染，1黑色，2白色
vector<int> g[510];
bool dfs(int u,int col) { //给i点染col色
    p[u]=col;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if(p[v]==col)//如果相邻的两个点颜色一样，那就是非法的
            return false;
        else if(p[v]==0) {
            if(col==1) {
                if(!dfs(v,2)) return false;
            }
            else {
                if(!dfs(v,1)) return false;
            }
        }
    }
    return true;
}

bool paint() {
    for(int i=1;i<=n;i++) {
        if(p[i]==0) {
            p[i]=1;
            if(!dfs(i,1))
                return false;
        }
    }
    return true;
}
