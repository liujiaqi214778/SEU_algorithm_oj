#include <stdio.h>
#include <string.h>

int num[1005];
int numtmp[1005];
int n;

void swap(int *a, int *b){
    int k = *a;
    *a = *b;
    *b = k;
}

inline int left(int v) { return (2 * v + 1); }
inline int right(int v) { return (2 * v + 2); }
inline int parent(int v) { return (v - 1) / 2; }

//小顶堆
void heap_adjust(int v) {
	int i = right(v);
	if (i > n) return;
	if (i == n) i--;  //无右孩子则直接选中左孩子
	else i = (num[i] < num[i - 1] ? i : i - 1); //选中孩子值最小的结点

	if (num[v] > num[i]) {
		swap(&num[v], &num[i]);
		heap_adjust(i);
	}
}

void to_heap() {
	int i = parent(n - 1);
	while (i >= 0) {
		heap_adjust(i--);
	}
}

int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &num[i]);
        to_heap();
        for(int i=0; i<n; i++){
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    return 0;
}
