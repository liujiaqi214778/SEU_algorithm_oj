#include <stdio.h>
#include <string.h>

const int MAXSIZE = 505;
const int INF = 0x3f3f3f3f;

struct MGraph {
	int edge[MAXSIZE][MAXSIZE];
	int vexnum, edgenum;
    void input(int n, int E){
        vexnum = n;
        edgenum = E;
        int u,v,w;
        clear();
        for(int i = 0; i < E; i++){
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            if(w < edge[u][v])
                edge[u][v] = edge[v][u] = w;
        }
    }
    int DIJ(int s, int t){
        int D[MAXSIZE];
        bool final[MAXSIZE];
        for (int i = 0; i < vexnum; i++) {
            D[i] = INF;
            final[i] = false;
        }
        D[s] = 0; final[s] = true;
        int imin = INF;
        for(int k = 1; k < vexnum; k++){  //第k短路径
            for(int i = 0; i < vexnum; i++){  //更新D
                if(!final[i] && D[s] + edge[s][i] < D[i])
                    D[i] = D[s] + edge[s][i];
            }
            imin = INF;
            for(int i = 0; i < vexnum; i++) //找到下一条最短路径
                if (!final[i] && D[i] < imin) {
                    imin = D[i];
                    s = i;
                }
            if(imin == INF) return -1;  //非连通图, s t没有路径
            final[s] = true;
            if(s == t) return D[s];  //已找到到目的地的最短路径, 直接返回
        }
        return -1;
    }
    void clear(){
        for(register int i = 0; i < vexnum; i++){
            for(register int j = 0; j < vexnum; j++)
                edge[i][j] = INF;
            edge[i][i] = 0;
        }
    }
} graph;

int main(){
    int m, n, E, s, t;
    scanf("%d", &m);
    while(m--){
        scanf("%d%d%d%d", &n, &E, &s, &t);
        graph.input(n, E);
        printf("%d\n", graph.DIJ(--s, --t));
    }
    return 0;
}
