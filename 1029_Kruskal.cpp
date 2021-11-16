#include <stdio.h>
#include <string.h>
#include <algorithm>

//并查集, 划分顶点集合
struct UFSet {
	UFSet(size_t n) {
		set = new int[n];
		size = n;
		reset();
	}
	~UFSet() { delete[] set;}
	int Find_f(unsigned int n) {
		if (n >= size) return -1;
		int i = n;
		while (set[i] >= 0) i = set[i];
		if(i != n) set[n] = i;
		return i;
	}
	void reset() { for(register int i = 0; i < size; i++) set[i] = -1;}
	int* set;
	size_t size;
};

struct Edge{
    int a,b,w;
    bool operator<(const Edge& e) const{ return w < e.w;}
};

const int MAXSIZE = 20008;
//Kruskal 稀疏图
struct KGraph {
	Edge edge[MAXSIZE];
	int vexnum, edgenum;

    void input(int n, int E){
        vexnum = n;
        edgenum = E;
        for(int i = 0; i < E; i++){
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);
            edge[i].a--;
            edge[i].b--;
        }
        std::sort(edge, edge+edgenum);  //边按权重排序
    }
    //依次选最小边,两个顶点不在集合则不构成环,并入集合
    int mst(){
        UFSet s(vexnum);
        int weight = 0, s1, s2;
        for(int i = 0; i < edgenum; i++){
            s1 = s.Find_f(edge[i].a);
            s2 = s.Find_f(edge[i].b);
            if(s1 != s2){
                weight += edge[i].w;
                s.set[s2] = s1; //union
            }
        }
        for(int i = 0, k = 0; i < vexnum; i++)
            if(s.set[i] < 0){
                k++;
                if(k > 1) return -1; // 非连通图不存在最小生成树
            }
        return weight;
    }
} graph;

int main(){
    int m, n, E;
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &n, &E);
        graph.input(n, E);
        printf("%d\n", graph.mst());
    }
    return 0;
}
