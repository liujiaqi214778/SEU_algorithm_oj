#include <stdio.h>
#include <string.h>
#include <stack>

//拓扑排序，输入时记录每个结点入度

const int MAXSIZE = 302;
struct Edge {
	int adjvex[MAXSIZE];      //邻接点下标
    int n;
    void push(int v){ adjvex[n++] = v; }
    void clear(){ n = 0; }
};

//静态邻接表
struct ALGraph {
	Edge vex[MAXSIZE];
	int indegree[MAXSIZE];    //有向图中每个结点的入度
    int out[MAXSIZE];
	int vexnum, edgenum, count;

    void input(int n, int m){
        vexnum = n; edgenum = m;
        clear();
        int x, y;
        while(m--){
            scanf("%d%d", &x, &y);  //下标1开始
            vex[x].push(y);
            indegree[y] += 1;
        }
    }

    void TopologicalSort() {
        std::stack<int> st;
        int v, adj;
        for(v = 1; v <= vexnum; v++)
            if(indegree[v] == 0)
                st.push(v);
        while(!st.empty()){
            v = st.top();
            st.pop();
            push(v);
            for(int k = 0; k < vex[v].n; k++){  //遍历所有邻边
                adj = vex[v].adjvex[k];
                if (!(--indegree[adj]))
                    st.push(adj);
            }
        }
        if(count < vexnum) printf("0\n");  // 存在环
        else{
            for(int i = 0; i < count; i++)
                printf("%d ", out[i]);
            printf("\n");
        }
    }

    void clear(){
        for(register int i = 1; i <= vexnum; i++){
            indegree[i] = count = 0;
            vex[i].clear();
        }
    }

    void push(int v){ out[count++] = v; }  //输出队列
} graph;


int main(){
    int M, n, m;
    scanf("%d", &M);
    while(M--){
        scanf("%d%d", &n, &m);
        graph.input(n, m);
        graph.TopologicalSort();
    }
    return 0;
}